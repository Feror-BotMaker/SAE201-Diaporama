#include "lecteurvue.h"
#include "ui_lecteurvue.h"

LecteurVue::LecteurVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LecteurVue)
{
    ui->setupUi(this);
    LModeActif = new QLabel("Mode Manuel", ui->statusbar);
    _changeurVitesse = new ChangeurVitesse(this);
    _numDiaporamaCourant = 0;   // =  le lecteur est vide
    _posImageCourante = 0;
    _vitesseDefil = 2;
    _estAuto = false;
    _aPropos = new PageAPropos;
    _timer = new QTimer(this);
    connect(this->ui->suivant, SIGNAL(clicked()), this, SLOT(avancer()));
    connect(this->ui->precedent, SIGNAL(clicked()), this, SLOT(reculer()));
    connect(_timer, SIGNAL(timeout()), this, SLOT(avancer()));
    connect(this->ui->lancer_diaporama, SIGNAL(clicked()), this, SLOT(demarrerAuto()));
    connect(this->ui->actionSortir, SIGNAL(triggered()), this, SLOT(sortir()));
    connect(this->ui->action_propos_de, SIGNAL(triggered()), this, SLOT(aPropos()));
    connect(this->ui->actionChanger_diaporama, SIGNAL(triggered()), this, SLOT(chargerDiaporama()));
    connect(this->ui->actionEnlever_diaporama, SIGNAL(triggered()), this, SLOT(viderDiaporama()));
    connect(this->ui->actionVitesse, SIGNAL(triggered()), this, SLOT(changerVitesse()));
}

LecteurVue::~LecteurVue()
{
    delete ui;
}

void LecteurVue::avancer()
{
    (this)->_posImageCourante = ((this)->_posImageCourante + 1) % nbImages();
    this->afficher();
}

void LecteurVue::demarrerAuto() {
    _timer->start(_vitesseDefil*1000); // Transformer en millisecondes
    disconnect(this->ui->lancer_diaporama, SIGNAL(clicked()), this, SLOT(demarrerAuto()));
    connect(this->ui->lancer_diaporama, SIGNAL(clicked()), this, SLOT(arreterAuto()));
    this->ui->lancer_diaporama->setText("Arrêter diaporama");
    _estAuto = true;
    LModeActif->setText("Mode Auto");
}

void LecteurVue::arreterAuto() {
    _timer->stop();
    disconnect(this->ui->lancer_diaporama, SIGNAL(clicked()), this, SLOT(arreterAuto()));
    connect(this->ui->lancer_diaporama, SIGNAL(clicked()), this, SLOT(demarrerAuto()));
    this->ui->lancer_diaporama->setText("Lancer diaporama");
    _estAuto = false;
    LModeActif->setText("Mode Manuel");
}


void LecteurVue::reculer()
{
    (this)->_posImageCourante = ((this)->_posImageCourante - 1) % nbImages();
    this->afficher();
}

void LecteurVue::sortir() {
    QCoreApplication::exit();
}

void LecteurVue::aPropos() {
    _aPropos->show();
}

void LecteurVue::changerVitesse() {
    bool etaitAuto = _estAuto;
    arreterAuto();
    _changeurVitesse->exec();
    _vitesseDefil = _changeurVitesse->getVitesse();
    if (etaitAuto) {
        demarrerAuto();
    }
}


void LecteurVue::changerDiaporama(unsigned int pNumDiaporama)
{
    // s'il y a un diaporama courant, le vider, puis charger le nouveau Diaporama
    if (numDiaporamaCourant() > 0)
    {
        viderDiaporama();
    }
    _numDiaporamaCourant = pNumDiaporama;
    if (numDiaporamaCourant() > 0)
    {
        chargerDiaporama(); // charge le diaporama courant
    }

}

void LecteurVue::chargerDiaporama()
{
    /* Chargement des images associées au diaporama courant
       Dans une version ultérieure, ces données proviendront d'une base de données,
       et correspondront au diaporama choisi */
    Image* imageACharger;
    imageACharger = new Image(3, "personne", "ATBGE", "/Users/feror/QtProjects/SAE201-Diaporama/Images/ATBGE.png");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(2, "personne", "Teletubies", "/Users/feror/QtProjects/SAE201-Diaporama/Images/blood_teletubies.jpg");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(4, "animal", "Kirby", "/Users/feror/QtProjects/SAE201-Diaporama/Images/buff_kirby.png");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(1, "personne", "Fraumag", "/Users/feror/QtProjects/SAE201-Diaporama/Images/chese.jpeg");
    _diaporama.push_back(imageACharger);


    // trier le contenu du diaporama par ordre croissant selon le rang de l'image dans le diaporama
        for (unsigned short int i = 0; i < _diaporama.size(); ++i)
        {
            for (unsigned short int j = 0; j < _diaporama.size() - i - 1; ++j)
            {
                if (_diaporama[j]->getRang() > _diaporama[j + 1]->getRang())
                {
                    // échanger les éléments
                    Image* temp = _diaporama[j];
                    _diaporama[j] = _diaporama[j + 1];
                    _diaporama[j + 1] = temp;
                }
            }
         }

     _posImageCourante = 0;
     afficher();
}

void LecteurVue::viderDiaporama()
{
    if (nbImages () > 0)
    {
        unsigned int taille = nbImages();
        for (unsigned int i = 0; i < taille ; i++)
        {
            _diaporama.pop_back(); /* Removes the last element in the vector,
                                      effectively reducing the container size by one.
                                      AND deletes the removed element */
        }
     _posImageCourante = 0;
    }
    cout << nbImages() << " images restantes dans le diaporama." << endl;
    afficher();
}

void LecteurVue::afficher()
{
    /* affiche les information sur le lecteur :
     * 1) vide (si num. de diaporama = 0) OU BIEN numéro de diaporama affiché
     * 2) Si un diaporama courant est chargé (num. de diaporama > 0), affiche l'image courante OU BIEN 'diaporama vide'
     *     si ce diaporama n'a aucun image */

    // 1)
    if (numDiaporamaCourant() == 0)
        cout << "vide" << endl;
    else
        cout << numDiaporamaCourant() << endl;

    // 2)
    if (nbImages() > 0) {
        imageCourante()->afficher();
        QPixmap imagePixmap = QPixmap(QString::fromStdString(imageCourante()->getChemin()));
        this->ui->image->setPixmap(imagePixmap);
        this->ui->categorie->setText(QString::fromStdString(imageCourante()->getCategorie()));
        this->ui->rang->setText(QString::number(imageCourante()->getRang()));
        this->ui->titre->setText(QString::fromStdString(imageCourante()->getTitre()));
    }
    else {
        cout << "diaporama vide" << endl;
        this->ui->image->setText("Image");
        this->ui->categorie->setText("Catégorie");
        this->ui->rang->setText("Rang");
        this->ui->titre->setText("Titre");
    }
}

unsigned int LecteurVue::nbImages()
{
    return _diaporama.size();
}

Image *LecteurVue::imageCourante()
{
    return _diaporama[_posImageCourante];
}

unsigned int LecteurVue::numDiaporamaCourant()
{
    return _numDiaporamaCourant;
}
