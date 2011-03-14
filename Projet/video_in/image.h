/* image.h */
#ifndef image_h
#define image_h
#include <png.h>


// Une image est un tableau de pixels (unsigned char, pour une image en niveaux de gris)
// On ne d�finit pas sa taille � l'avance, cela permettra de faire des simulations avec des images plus petites...
typedef struct Image {
    int   width, height;  
    unsigned char  *pixel; 
} Image;


// Comme les fonctions suivantes sont appel�es � partir de C++, il est n�cessaire de mettre quelques
// en-t�tes sp�ciales, pour que le linker sache linker des fonctions C pures avec du C++

#ifdef __cplusplus
extern "C" {
#endif
    
    void   image_read(Image * image, char *filename);
    void   image_write(Image * image, char *filename);
    
#ifdef __cplusplus
}
#endif


#endif
