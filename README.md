# 🧑‍💻 Projet Synthèse d’Image (SI)

Bienvenue dans mon projet de **Synthèse d’Image**.  
Ce dépôt contient l’ensemble du code que j’ai développé dans le cadre de ce cours, afin d’explorer les bases de la **modélisation**, des **transformations géométriques**, du **rendu** et de l’**éclairage** en C.

---

## 🧭 Objectifs

L’objectif de ce projet est de mettre en pratique les notions vues en cours :

- Construire et manipuler une scène 3D simple.  
- Implémenter des transformations affines (translation, rotation, mise à l’échelle).  
- Gérer les axes, repères et transformations caméra.  
- Appliquer des modèles d’éclairage locaux (Lambert, Phong…).  
- Intégrer et utiliser des textures.  
- Offrir des interactions clavier pour modifier dynamiquement la scène.  

---

## 📁 Structure de mon dépôt

Voici les principaux fichiers qui composent mon projet :

- `main.c` → Point d’entrée du programme  
- `init.c`, `init.h` → Initialisation de la scène, des objets et des lumières  
- `affines.c`, `affines.h` → Transformations géométriques (rotation, translation, échelle)  
- `axes.c`, `axes.h` → Gestion des axes et repères  
- `lumiere.c`, `lumiere.h` → Calcul de la lumière et de l’éclairage  
- `texture.c` → Chargement et application des textures (`.ppm`)  
- `opmat.c`, `opmat.h` → Opérations matricielles  
- `switch_blend.c`, `switch_light.h` → Gestion des effets lumineux et blending  
- `actions.c`, `actions.h` → Gestion des interactions utilisateur  
- `touches.h` → Raccourcis clavier  
- `herbe.ppm` → Exemple de texture  
- `test` → Programme de test et de démonstration

---

## 🧮 Fonctionnalités que j’ai développées

- Application de transformations affines sur les objets de la scène  
- Systèmes de coordonnées et repères dynamiques  
- Calcul d’éclairage avec différentes intensités et effets  
- Application d’une texture sur une surface (ex. herbe)  
- Possibilité de changer les effets de lumière et de blending  
- Interaction en temps réel via le clavier  
- Tests pour valider les modules et les transformations

---

## 💻 Compilation et exécution

Pour compiler le projet, j’utilise `gcc` :

```bash
gcc -o synthese main.c init.c affines.c axes.c lumiere.c texture.c opmat.c switch_blend.c actions.c -lm
