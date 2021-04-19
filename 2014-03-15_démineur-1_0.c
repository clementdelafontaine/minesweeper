#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>
#include <myconio.h>

// Menu
void menu ()
{	system ("cls");
	printf ("--------------------------------------------------------------------------------\n");
	printf ("---------------------------------LE MINESWEEPER---------------------------------\n");
	printf ("--------------------------------------------------------------------------------\n\n");
	printf ("                      ##########\n");
	printf ("                      ## MENU ##\n");
	printf ("                      ##########\n\n\n");
	printf ("                                   1 \20 D\202buter la partie\n\n");
	printf ("                                   2 \20 Statistiques\n\n");
	printf ("                                   3 \20 R\212gles\n\n");
	printf ("                                   4 \20 Quitter\n\n\n\n\n\n\n\n");
	printf ("--------------------------------------------------------------------------------\n");
	printf ("################################################################################\n");
	printf ("--------------------------------------------------------------------------------\n");
	printf ("                   Entrez la valeur correspondante \205 votre choix : ");
}

// Fonction permettant de colorer les caractères
void color(int t,int f)
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(H,f*16+t);
}

// Fonction qui génère un nombre entre 1 et 10
int AL (int min, int max)
{	return ((rand () % (max - min + 1)) + min);	
}

// Affichage de la grille joueur ; reçoit la valeur du tableau et du nombre de drapeaux restants
void Affichage (int tab[12][12], int drapeau)
{	int i, j;
	system ("cls");
	printf ("\n\n\n\n                             1  2  3  4  5  6  7  8  9  10		\n Drapeaux restants = %d\n\n", drapeau);
	for (i = 1; i < 11; i++)
	{	if (i < 10)
		{	printf ("                        %d   ", i);
		}
		else
		{	printf ("                       %d   ", i);
		}
		for (j = 1; j < 11; j++)
		{	if (tab[i][j] == 42)
			{	color(15,0);
				printf (" . ");
				color(7,0);
			}
			if (tab[i][j] == 0)
			{	printf ("   ");
			}
			if ((tab[i][j] > 0) && (tab[i][j] < 9))
			{	if (tab[i][j] == 1)
				{	color(9,0);
					printf (" 1 ");
					color(7,0);
				}
				if (tab[i][j] == 2)
				{	color(2,0);
					printf (" 2 ");
					color(7,0);
				}
				if (tab[i][j] == 3)
				{	color(4,0);
					printf (" 3 ");
					color(7,0);
				}
				if (tab[i][j] == 4)
				{	color(3,0);
					printf (" 4 ");
					color(7,0);
				}
				if (tab[i][j] == 5)
				{	color(8,0);
					printf (" 5 ");
					color(7,0);
				}
				if (tab[i][j] == 6)
				{	color(8,0);
					printf (" 6 ");
					color(7,0);
				}
				if (tab[i][j] == 7)
				{	color(5,0);
					printf (" 7 ");
					color(7,0);
				}
				if (tab[i][j] == 8)
				{	color(3,0);
					printf (" 8 ");
					color(7,0);
				}
			}
			if (tab[i][j] == -1)
			{	color(12,0);
				printf (" \17 ");
				color(7,0);
			}
			if (tab[i][j] == 30)
			{	color(14,0);
				printf (" # ");
				color(7,0);
			}
			if (tab[i][j] == - 2)
			{	color(14,0);
				printf (" * ");
				color(7,0);
			}
		}				
		printf("\n\n");
	}
	printf("\n\n\n");
}
	
// Lecture des statistiques
void lect (int tab[10], int score[3], char nom[30])
{	FILE * fichier = NULL;
	fichier = fopen("stat.txt", "r");
    if (fichier != NULL)
    {	fscanf (fichier, "Parties jouées : %d Parties gagnées : %d %s %d %d %d", &tab[0], &tab[1], nom, &score[0], &score[1], &score[2]);
		fclose (fichier);
	}
    else
    {	printf ("Impossible d'ouvir le fichier statistiques.txt\n");
    }
}

// Animation partie perdue
void perdu ()
{	int i;
	color(14,0);
	for (i = 31; i < 60; i = i + 3)
	{	gotoxy (i, 8);
		printf ("\b*");
		Sleep (40);
	}
	for (i = 8; i < 27; i = i + 2)
	{	gotoxy (58, i);
		printf ("\b*");
		Sleep (40);
	}
	for (i = 55; i > 30; i= i - 3)
	{	gotoxy (i, 26);
		printf ("\b*");
		Sleep (40);
	}
	for (i = 26; i > 8; i = i - 2)
	{	gotoxy (31, i);
		printf ("\b*");
		Sleep (40);
	}
	for (i = 34; i < 57; i = i + 3)
	{	gotoxy (i, 10);
		printf ("\b*");
		Sleep (40);
	}
	for (i = 12; i < 25; i = i + 2)
	{	gotoxy (55, i);
		printf ("\b*");
		Sleep (40);
	}
	for (i = 55; i > 33; i = i - 3)
	{	gotoxy (i, 24);
		printf ("\b*");
		Sleep (40);
	}
	for (i = 22; i > 11; i = i - 2)
	{	gotoxy (34, i);
		printf ("\b*");
		Sleep (40);
	}
	for (i = 37; i < 53; i = i + 3)
	{	gotoxy (i, 12);
		printf ("\b*");
		Sleep (40);
	}
	for (i = 14; i < 23; i = i + 2)
	{	gotoxy (52, i);
		printf ("\b*");
		Sleep (40);
	}
	for(i = 49; i > 36; i = i - 3)
	{	gotoxy (i, 22);
		printf ("\b*");
		Sleep (40);
	}
	for(i = 20; i > 13; i = i - 2)
	{	gotoxy (37, i);
		printf ("\b*");
		Sleep (40);
	}
	for(i = 40; i < 50; i = i + 3)
	{	gotoxy (i, 14);
		printf ("\b*");
		Sleep (40);
	}
	for(i = 16; i < 23; i = i + 2)
	{	gotoxy (49, i);
		printf ("\b*");
		Sleep (40);
	}
	for(i = 46; i > 39; i = i - 3)
	{	gotoxy (i, 20);
		printf ("\b*");
		Sleep (40);
	}
	for(i = 18; i > 15; i = i - 2)
	{	gotoxy (40, i);
		printf ("\b*");
		Sleep (40);
	}
	 for(i = 43; i < 47; i = i + 3)
	 {	gotoxy (i, 16);
		 printf ("\b*");
		 Sleep (40);
	 }
	for(i = 46; i > 42; i = i - 3)
	{	gotoxy (i, 18);
		printf ("\b*");
		Sleep (40);
	}
	color(7,0);
	gotoxy (1, 30);
}

// Lecture prénom et chrono
/*void lectscore (int temps[25], char nom[30])
{	FILE * fichier = NULL;
	fichier = fopen("stat.txt", "r");
    if (fichier != NULL)
    {	fscanf (fichier, "\n %d:%d:", &score[0], &score[1]);
		fscanf (fichier, "\n\n %d:%d:", &score[2], &score[3]);
		fscanf (fichier, "\n\n\n %d:%d:", &score[4], &score[5]);
		fscanf (fichier, "\n\n\n\n %d:%d:", &score[6], &score[7]);
		fscanf (fichier, "\n\n\n\n\n %d:%d:", &score[8], &score[9]);
		fscanf (fichier, "\n%s %d:%d", nom, &score[10], &score[11]);
		fclose (fichier);
	}
	else
	{	printf ("Impossible d'ouvir le fichier statistiques.txt");
	}
}*/
	
// Affichage statistiques
void affstat (int tab[10], int temps[3], char nom[30])
{	double p;
	char b = '%';
	tab[2] = tab[0] - tab[1];
	p = (float)tab[1] / (float)tab[0] * 100;
	printf ("--------------------------------------------------------------------------------\n");
	printf ("---------------------------------STATISTIQUES-----------------------------------\n");
	printf ("--------------------------------------------------------------------------------\n");
	printf ("\n\nParties jou\202es : %d\n\nParties gagn\202es : %d\n\nParties perdues : %d\n\nPourcentage de r\202ussite : %lf %c \n\n\n\n", tab[0], tab[1], tab[2], p, b);
	printf ("--------------------------------------------------------------------------------\n");
	printf ("--------------------------------DERNIER  TEMPS----------------------------------\n");
	printf ("--------------------------------------------------------------------------------\n");
	printf ("\n%s........................ %d mines en %02dm:%02ds\n\n\n\n\n\n\n\n\n", nom, temps[2], temps[0], temps[1]);
}

// Sauvegarde statistiques
void save (int tab[10], int temps[3], char nom[30])
{	FILE * fichier = NULL;
	fichier = fopen("stat.txt", "w+");
    if (fichier != NULL)
    {	fprintf (fichier, "Parties jouées : %d Parties gagnées : %d %s %d %d %d", tab[0], tab[1], nom, temps[0], temps[1], temps [2]);
		fclose (fichier);
	}
	else
	{	printf ("Impossible d'ouvir le fichier statistiques.txt");
	}
}


// Conversion sec en mm:ss
int chrono (int a, int tab[3])
{	int b, c;
	if (a >= 60)
	{	b = a % 60;
		c = a - b;
		tab[0] = c / 60;
		a = b;
	}
	if (a >= 0)
	{	tab[1] = a;
	}
}

// Jeu
bool jeu (int tab[10], int temps[4], char nom[30])
{	srand (time (NULL));
// Déclaration tableau (2 lignes et 2 colonnes tampon = 0 et 11 => grille de 1 à 10)
	int secret[12][12] = {0}, i, j, m, n;

// Nombre de mines
	int mines;
// Demander le nombre de mines
	do 
	{	printf("\n\n\n\nEntrez le nombre de mines souhait\202 (entre 5 et 60) : ");
		if (scanf ("%d", &mines))
		{}
		else
		{	getchar ();
			mines = 0;
		}
		system ("cls");
	} while ((mines < 5) || (mines > 60));

// Placement des mines (-1) dans la zone de grille
	i = 0;
	while (i < mines)
	{	m = AL (1, 10);
		n = AL (1, 10);
		if (secret[m][n] == 0)
		{	secret[m][n] = -1;
			i++;
		}
	} 

// Calcul des cases adjacentes aux mines
	for (m = 1; m < 11; m++)
	{	for (n = 1; n < 11; n++)
		{	if (secret[m][n] == -1)
			{	for (i = m - 1; i <= m + 1; i++)
				{	for (j = n - 1; j <= n + 1; j++)
					{	if (secret[i][j] != -1)
						{	secret[i][j] = secret[i][j] + 1;
						}
					}
				}
			}
		}
	}

//Affichage du tableau test sans zone tampon
//	Affichage (secret, 0);
	
// Création grille joueur
// Grille effective de 1 à 10
	int grille[12][12];
	for (i = 0; i < 12; i++)
	{	for (j = 0; j < 12; j++)
		{	grille[i][j] = 42;
		}
	}
// Premier Affichage grille vierge
	Affichage (grille, mines);
	
// Boucle de jeu
	int l, c, ld, cd, cpt, nd, drapeau;
	// Déclaration et déclenchement du timer
	time_t start, end;
	double diff_t;
	bool continuer, test;
	continuer = true;
	test = false;
	time(&start);
	do
	{	// Demande d'entrée de la part du joueur
		while (test == false)
		{	printf ("Pour placer un drapeau entrez 0 0\nPour enlever un drapeau entrez 0 1\nEntrez le num\202ro de ligne puis de colonne (l c) : \n");
			if (scanf ("%d %d", &l, &c))
			{}
			else
			{	getchar ();
				l = 42;
				c = 42;
			}
			if ((l < 1) || (l > 10) || (c < 1) || (c > 10))
			{	if ((l < 0) || (l > 10) || (c < 0) || (c > 10) || ((l == 0) && (c > 1)) || ((l > 1) && (c == 0)))
				{	printf("Valeurs invalides, recommencez.\n\n");
				}
				// Placer un drapeau
				if ((l == 0) && (c == 0))
				{	while (test == false)
					{	printf ("Pour quitter ce mode entrez 0 0\nPlacer un drapeau - Entrez le num\202ro de ligne puis de colonne (l c) : \n");
						if (scanf ("%d %d", &ld, &cd))
						{}
						else
						{	getchar();
							ld = 42;
							cd = 42;
						}
						if ((ld < 0) || (ld > 10) || (cd < 0) || (cd > 10) || ((ld == 0) && (cd > 0)) || ((ld > 0) && (cd == 0)))
						{	printf ("Valeurs invalides, recommencez.\n\n");
						}
						else
						{	if ((ld == 0) && (cd == 0))
							{	test = true;
								l = 42;
								c = 42;
							}
							else
							{	// Si drapeau déjà présent ou case dévoilée
								if ((grille[ld][cd] == 30) || (grille[ld][cd] >= 0) && (grille[ld][cd] < 9))
								{	printf ("Action impossible, case occupp\202e par un drapeau ou d\202voil\202e.\n\n");
								}
								else
								{	grille[ld][cd] = 30;
									l = 42;
									c = 42;
									test = true;
								}
							}
						}
					}
				}
				// Enlever un drapeau
				if (((l == 0) && (c == 1)) || ((l == 1) && (c == 0)))
				{	while (test == false)
					{	printf ("Pour quitter ce mode entrez 0 0\nEnlever un drapeau - Entrez le num\202ro de ligne puis de colonne (l c) : \n");
						if (scanf ("%d %d", &ld, &cd))
						{}
						else
						{	getchar ();
							ld = 42;
							cd = 42;
						}
						if ((ld < 0) || (ld > 10) || (cd < 0) || (cd > 10) || ((ld == 0) && (cd > 0)) || ((ld > 0) && (cd == 0)))
						{	printf ("Valeurs invalides, recommencez.\n\n");
						}
						else
						{	if ((ld == 0) && (cd == 0))
							{	test = true;
								l = 42;
								c = 42;
							}
							else
							{	// Si pas de drapeau
								if (grille[ld][cd] != 30)	
								{	printf ("Pas de drapeau dans cette case\n\n");
								}									
								else
								{	grille[ld][cd] = 42;
									l = 42;
									c = 42;
									test = true;
								}
							}		
						}
					}
				}
			}
			// else => valeurs valides
			else
			{	test = true;
				// Si drapeau déjà présent
				if (grille[l][c] == 30)
				{	printf ("Action impossible, case occupp\202e par un drapeau.\n\n");
					test = false;
				}
				// Si case déjà dévoilée
				if ((grille[l][c] >= 0) && (grille[l][c] < 9))
				{	printf ("Action impossible, case d\202j\205 d\202voil\202e.\n\n");
					test = false;
				}	
			}
		}
		// Réinitiallisation du booléen pour le prochain tour
		test = false;
		
		// Attribution des valeurs de la case entrée (valeurs : mine = -1, vide(0) = 0, drapeau = 30)
		
		if (secret[l][c] == -1)
		{	grille[l][c] = -1;
			continuer = false;
		}
		else
		{	if (l != 42)
			{	grille[l][c] = secret[l][c];
			}
		}
		

		// Dévoilement progressif de part en part des cases vides dévoilées
		for(cpt = 0; cpt < 9; cpt++)
		{	for (m = 1; m < 11; m++)
			{	for (n = 1; n < 11; n++)
				{	if (grille[m][n] == 0)
					{	for (i = m - 1; i <= m + 1; i++)
						{	for (j = n - 1; j <= n + 1; j++)
							{	grille[i][j] = secret[i][j];
							
							}
						}
					}
				}
			}
		}
		// Compteur de cases dévoilées
		nd = 0;
		for (m = 1; m < 11; m++)
			{	for (n = 1; n < 11; n++)
				{	if ((grille[m][n] < 9) && (grille[m][n] >= 0))
					{		nd = nd + 1;
					}
				}
			}
		// Compteur mines
		drapeau = mines;
		for (i = 1; i < 11; i++)
			{	for (j = 1; j < 11; j++)
				{	if (grille[i][j] == 30)
					{		drapeau = drapeau - 1;
					}
				}
			}
		// Affichage grille en cours de jeu 
		//Affichage (secret, drapeau);
		Affichage (grille, drapeau);
		
		// Mine touchée
		if (continuer == false)
		{	Affichage (secret, drapeau);
			perdu ();
			printf ("Vous avez perdu\n\n");
			temps[3] = 0;
		}
		// Victoire
		if (nd == 100 - mines)
		{	Affichage (secret, drapeau);
			printf ("\nVictoire !! Bien jou\202 %s !\n", nom);
			// Chronomètre
			time(&end);
			diff_t = (int) difftime (end, start);
			chrono (diff_t, temps);
			printf("Votre temps : %02dm:%02ds\n\n", temps[0], temps[1]);
			continuer = false;
			// Compteur victoires
			tab[1] = tab[1] + 1;
			temps[2] = mines;
			// Condition de sauvegarde
			temps[3] = 1;
		}
	} while (continuer == true);
}

// Règles
void regles ()
{	printf ("\n\n\nLe d\202mineur est un jeu de r\202flexion dont le but est de localiser des mines\ncach\202es dans un champ virtuel avec pour seule indication le nombre de mines\ndans les zones adjacentes.\nLe champ de mine est repr\202sent\202 par une grille et chaque case de la grille peut soit cacher une mine, soit \210tre vide.\nLe but du jeu est de d\202couvrir toutes les cases libres sans faire exploser les\nmines, c'est-\205-dire sans d\202voiler les cases qui les dissimulent.\nLorsque le joueur d\202voile une case libre et que toutes les cases adjacentes le\nsont \202galement, une case vide est affich\202e.\nSi en revanche au moins l'une des cases avoisinantes contient une mine,\nun chiffre appara\214t, indiquant le nombre de cases adjacentes contenant une mine.\nEn comparant les diff\202rentes informations r\202colt\202es, le joueur peut ainsi\nprogresser dans le d\202minage du terrain.\nOn peut signaler les cases contenant des mines pr\202sum\202es par un drapeau.\nLe jeu est chronom\202tr\202, ce qui permet de conserver les meilleurs scores.\n\n");
}

int main ()
{	
	char a, nom[30];
	int ch;
	bool  quit = false;
	// Tableau des temps
	int temps[4] = {0};
	int score[3];
	// aller lire victoires et parties
	int stat[10] = {0};
	while (quit == false)
	{	menu ();
		if (scanf ("%d", &ch))
		{}
		else
		{	getchar ();
			ch = 0;
		}
		// Aller lire stats
		lect (stat, score, nom);
		switch (ch)
		{	case 1:
				system ("cls");
				printf ("\n\n\n\nEntrez votre nom (sans accents): ");
				scanf ("%s", nom);
				system ("cls");
				do
				{	jeu (stat, temps, nom);
					do
					{	printf ("Voulez-vous rejouer ? (y/n)");
						scanf("%s", &a);
					} while ((a != 'n') && (a != 'y'));
					// Compteur parties
					stat[0] = stat[0] + 1; 
					// Si le joueur gagne on sauvegarde son temps
					if (temps[3] == 1)
					{	save (stat, temps, nom);	
					}
				} while (a == 'y');
				break;
			case 2:
				system ("cls");
				affstat (stat, score, nom);
				system ("pause");
				break;
			case 3:
				system ("cls");
				regles ();
				system ("pause");
				break;
			case 4 :
				quit = true;
				system ("cls");
				break;
			default:
				printf ("\n                   Valeur invalide\n\n                   ");
				system ("pause");
				break;
		}
	}
	return 0;
}