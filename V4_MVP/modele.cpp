#include "modele.h"

Modele::Modele()
{
    _numDiaporamaCourant = 0;   // =  le lecteur est vide
    _tapisPlaceHolder = new Image(0, "Catégorie", "Titre", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_tapis.gif");
}

void Modele::avancer()
{
    (this)->_posImageCourante = ((this)->_posImageCourante + 1) % nbImages();
}

void Modele::reculer()
{
    (this)->_posImageCourante = ((this)->_posImageCourante - 1) % nbImages();
}

void Modele::changerDiaporama(unsigned int pNumDiaporama)
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

void Modele::chargerDiaporama()
{
    /* Chargement des images associées au diaporama courant
       Dans une version ultérieure, ces données proviendront d'une base de données,
       et correspondront au diaporama choisi */
    Image* imageACharger;
    imageACharger = new Image(1, "Bâtimment", "Chateau pas symétrique", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_0.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(2, "Animaux", "Un chien et un chat je crois", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_1.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(3, "Princesse", "Je sais pas qui c'est", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_2.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(4, "Animaux", "Orphelin.", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_3.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(5, "Princesse", "La meuf qui a pris trop d'calmants", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_4.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(6, "Animaux", "Le canard dans le dessin animé là", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_5.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(7, "Animaux", "Le clodo et la jolie", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_6.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(8, "Princesse", "Aladd'2", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_7.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(9, "Bâtimment", "L'autre canard dans l'dessin animé là", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_8.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(10, "Animaux", "C'est encore le même canard", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_9.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(11, "Animaux", "木兰之龙", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_10.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(12, "Animaux", "L'éléphant qui vole avec ses oreilles (ça fait peur)", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_11.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(13, "Animaux", "Un rat avec des gun", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_12.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(14, "Animaux", "Un chat qui lèche la terre ???", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_13.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(15, "Animaux", "La femme de monsieur Mouse", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_14.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(16, "Animaux", "Le chien qui promène un chien", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_15.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(17, "Animaux", "Le même chien en train de peindre", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_16.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(18, "Animaux", "Un canard sur l'internet ? C'est quoi ces images ??", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_17.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(19, "Animaux", "J'ai peur.", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_18.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(20, "Animaux", "Monsieur Mouse, homme d'affaire multimiliardaire.", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_19.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(21, "Animaux", "Le chien qui recolore sa chaussure", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_20.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(22, "Princesse", "La meuf avec une seule chaussure", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_21.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(23, "Vacances", "Une souris qui bronze", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_22.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(24, "Criminel de guerre", "Le gars qui jète l'enfant", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_23.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(25, "Combattant", "OMG elle rentre dans l'armée (sa tourne mal)", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_24.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(26, "Animaux", "Le gars qui te mange le bras si tu lui donne des pièces.", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_25.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(27, "Animaux", "El perro tantaratan tantan", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_26.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(28, "Animaux", "Le Batard qui mange mon miel.", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_27.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(29, "Animaux", "Le harouf qui traine avec l'ours", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_28.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(30, "Objets", "Le gars en bois qui aurait bien besoin d'un taille-crayon", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_29.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(31, "Animaux", "Le chien qui est promené par un autre chien", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_30.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(32, "Animaux", "Le harouf du roi lion", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_31.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(33, "Animaux", "La gadji du roi lion", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_32.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(34, "Animaux", "Simba le terrible, roi des lions", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_33.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(35, "Animaux", "Un cafard faché", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_34.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(36, "Animaux", "Les chats dans le film \"chats 4\"", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_35.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(37, "Animaux", "Le poisson-femme là", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_36.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(38, "Animaux", "Le boug qui recycle les chats (c aussi un sonographe)", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_37.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(39, "Animaux", "Le clodo de la savanne", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_38.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(40, "Animaux", "Le tigre engagé dans l'armée (il respecte les conventions de genève)", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_39.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(41, "Animaux", "Le pote du gros dans Royauté Féline", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_40.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(42, "Jouets", "Bouz leclair et Lebois le garçon-vache", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_41.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(43, "Jouets", "Un visiteur, venu d'ailleur. OOOOOOOOOOOOH.", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_42.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(44, "Animaux", "L'antithèse de la bienpensance, les trois mousquetaire des crimes de guerres.", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_43.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(45, "Princesse", "Encore une princesse.", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_44.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(46, "Bâtimment", "Une princesse de plus ?", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_45.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(47, "Princesse", "La femme de ménage", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_46.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(48, "Princesse", "Mais pourquoi y'en a autant", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_47.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(49, "Princesse", "L'esclavagiste d'enfants, de nains et d'annimaux.", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_48.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(50, "Princesse", "Et une de plus.", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_49.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(51, "Animaux", "Encore un hybride étrange entre une femme et un poisson.", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_50.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(52, "Princesse", "L'esclavagiste, le retour", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_51.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(53, "Princesse", "Je connais pas son nom", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_52.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(54, "Princesse", "Je sais pas qui c'est", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_53.gif");
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

     cout << "Diaporama num. " << numDiaporamaCourant() << " selectionne. " << endl;
     cout << nbImages() << " images chargees dans le diaporama" << endl;

    _unEtat = Manuel;
}

void Modele::viderDiaporama()
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
    _unEtat = Déchargé;
}

void Modele::afficher()
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
    if (nbImages() > 0)
        imageCourante()->afficher();
    else
        cout << "diaporama vide" << endl;
}

unsigned int Modele::nbImages()
{
    return _diaporama.size();
}

Image *Modele::imageCourante()
{
    if (_unEtat == Déchargé) {
        return _tapisPlaceHolder;
    } else {
        return _diaporama[_posImageCourante];
    }
}

unsigned int Modele::numDiaporamaCourant()
{
    return _numDiaporamaCourant;
}


Modele::Etat Modele::getEtat() {
    return _unEtat;
}

int Modele::getVitesse() {
    return _vitesseActuelle;
}

void Modele::setVitesse(int vitesse) {
    _vitesseActuelle = vitesse;
}

void Modele::toggleAuto() {
    if (_unEtat == Automatique) {
        _unEtat = Manuel;
    } else if (_unEtat == Manuel) {
        _unEtat = Automatique;
        _posImageCourante = 0;
    }
}
