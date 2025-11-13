# 🕹️ so_long

Petit jeu 2D en C développé avec la **MiniLibX** dans le cadre du cursus **École 42**.  
Le but : **ramasser tous les objets, éviter les ennemis et atteindre la sortie !**  
Un projet fun pour découvrir la gestion d’événements, le rendu graphique et la structure d’un moteur de jeu minimaliste.  

---

## 🎮 Présentation

**so_long** est un mini jeu en 2D réalisé en **C** avec la **MiniLibX**.  
Le but du jeu est simple :

> 🪙 Ramasse toutes les pièces, 👾 évite les ennemis et 🚪 rejoins la sortie pour gagner !

Ce projet permet de découvrir :
- la **programmation graphique**
- la **gestion d’événements clavier**
- la **manipulation d’images**
- la **validation et le parsing de maps**
- et surtout, la **logique de rendu d’un mini moteur de jeu**.

---

## 🧩 Fonctionnalités

- 🧭 Déplacement fluide du joueur (↑ ↓ ← →) 
- 🪙 Collecte d’objets à ramasser
- 🚪 Sortie déverrouillée après avoir tout ramassé
- 🧱 Map personnalisable via un fichier `.ber`
- ❌ Gestion d’erreurs (map invalide, fichier corrompu, etc.)
- 🧠 Validation de map par **flood fill** (bonus)
- 👾 Ennemi animé (bonus)

---

## 🗺️ Exemple de map `.ber`

```txt
1111111
1P0C0E1
1000001
1111111
