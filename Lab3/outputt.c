# i n c l u d e   < u n i s t d . h > 

 # i n c l u d e   < f c n t l . h > 

 # i n c l u d e   < s t d l i b . h > 

 # i n c l u d e   < s y s / t y p e s . h >   / *   d e f i n e s   t y p e s   u s e d   b y   s y s / s t a t . h   * / 

 # i n c l u d e   < s y s / s t a t . h >   / *   d e f i n e s   S _ I R E A D   &   S _ I W R I T E   * / 

 # i n c l u d e   < s t d i o . h > 

 # d e f i n e   F I L E _ M O D E   ( S _ I R U S R   |   S _ I W U S R   |   S _ I R G R P |   S _ I W G R P   |   S _ I R O T H   |   S _ I W O T H ) 

 / * J o h n   M e y e r s   C O S C   3 5 0 

   * T h i s   p r o g r a m   t a k e s   a   f i l e   i n   f o r m   t h e   c o m m a n d   l i n e   a n d   l e t s   t h e   u s e r   c r e a t e   a   n e w   f i l e   b y   c o m m a n d   l i n e   i n p u t 

   * i t   r e a d s   f r o m   t h e   f i r s t   f i l e   w h i l e   e r r o r   c h e c c k i n g   a n d   r e a d s   i n   c h a r a c h t e r s   t o   b e   c o n v e r t e d   t i   A S C I I   c o d e 

   * a n d   w r i t e   t h a t   c o d e   t o   t h e   n e w   c r e a t e d   f i l e   w i t h   a   s p a c e   i n   b e t w e e n   e a c h   o f   t h e m   

     * / 

 i n t   m a i n ( i n t   a r g c ,   c h a r   * a r g v [ ] ) { 

 	 

 	 i f ( a r g c   <   3 ) { 

 	 	 p r i n t f ( " n e e d   t w o   a r g u m e n t s   f o r   i n p u t   a n d   o u t p u t " ) ; 

 	 	 r e t u r n   - 1 ; 

 	 } / / c h e c k s   t o   m a k e   s u r e   t h e r e   a r e   t w o   a r g u m e n t s 

 	 i n t   s o u r c e ,   t a r g e t ; 

 	 i f ( ( s o u r c e   =   o p e n ( a r g v [ 1 ] ,   O _ R D O N L Y ) )   <   0 ) { 

 	 	 p r i n t f ( " f i l e   o p e n   e r r o r " ) ; 

 	 } 

 	 t a r g e t   =   o p e n ( a r g v [ 2 ] ,   O _ W R O N L Y   |   O _ C R E A T   |   O _ E X C L ,   F I L E _ M O D E ) ; 

 	 i f ( t a r g e t   ! =   - 1 ) { / /   g o e s   t h r o u g h   t h e   f u n c t i o n   o n l y   i f   t h e   f i l e   h a s   n o t   y e t   b e e n   c r e a t e d 

 	 	 c h a r   c h ; 

 	 	 i n t   h o l d ,   p u t ; 

 	 	 i f ( ( p u t   =   d u p 2 ( t a r g e t ,   1 ) )   <   0 ) { 

 	 	 	 p r i n t f ( " e r r o r " ) ; 

 	 	 } 

 	 	 w h i l e ( ( r e a d ( s o u r c e ,   & c h ,   1 ) )   >   0 ) { 

 	 	 	 i f ( c h   = =   1 0 ) 

                         	 	 {   

                         	 	         p r i n t f ( " \ n " ) ; 

                         	 	 } 

                         	 	 i f ( & c h   = =   "   " ) 

                         	 	 { 

                         	 	         p r i n t f ( " % d   " ,   ( i n t ) c h ) ; 

                         	 	 } / /   c o n v e r t s   t h e   c h a r s   t o   i n t e g e r s   m e a n i n g   i t   w i l l   p r i n t A S C I I   c o d e   w e   d o n t   n e e d   a n y   c o n v e r s i o n   h e r e 

                         	 	 p r i n t f ( " % d   " ,   c h ) ; 

 	 	 } 

 	 c l o s e ( s o u r c e ) ; 

 	 c l o s e ( t a r g e t ) ; 

 	 } 

 	 e l s e { 

 	 	 p r i n t f ( " o p e n   t a r g e t   f i l e   e r r o r " ) ; 

 	 } 

 	 r e t u r n   0 ; 

 } 

 