��# i n c l u d e   " m o u s e . h " 
 
 # p r a g m a   c o m m e n t ( l i n k e r ,   " / S T A C K : 1 0 2 4 0 0 0 0 0 0 , 1 0 2 4 0 0 0 0 0 0 " ) 
 
 
 
 i n t   m i n S t e p = 1 0 0 0 0 ; 
 
 s t r u c t   n o d e 
 
 { 
 
 	 i n t   x , y , p r e , s t e p ; 
 
 } ; 
 
   
 
   / * 
 
   *   B F S �e�X�v�Q�[  ^�^OHQd"}  
 
   * /   
 
 c l a s s   Q u e u e / / R�^ N*N�R{|�
N^\�N%N<haIN
N�v�R	�  
 
 { 
 
 	 p r i v a t e   : 
 
 	 	 n o d e   q u e u e [ 1 0 0 0 0 ] ; / / �[IN�R'Y\  
 
 	 	 S t a c k   b e s t ;   / / (uegl�bc�vh  
 
 	 	 i n t   p I n , p O u t ; / / �[IN$N*Nc��(u�NcT�R�veQ�p I n �T�Q�p O u t �vMOn  
 
 	 p u b l i c   : 
 
 	 	 v o i d   p u s h   ( i n t   x , i n t   y , i n t   p r e , i n t   s t e p ) / / �ReQ�R-N  \ň�v�~�g:Nn o d e   S+T  PWh  x ,   PWhy ,   MRq�p r e , ekpes t e p   
 
 	 	 { 
 
 	 	 	 p O u t + + ; / / c���e�Xzz��
 
 	 	 	 / / �ReQ�R-N  
 
 	 	 	 q u e u e [ p O u t ] . x = x ; 
 
 	 	 	 q u e u e [ p O u t ] . y = y ; 
 
 	 	 	 q u e u e [ p O u t ] . p r e = p r e ; 
 
 	 	 	 q u e u e [ p O u t ] . s t e p = s t e p ; 
 
 	 	 } 
 
 	 	 v o i d   p u s h   ( n o d e   t e m p ) / / T
N    
 
 	 	 { 
 
 	 	 	 p O u t + + ; 
 
 	 	 	 q u e u e [ p O u t ] = t e m p ; 
 
 	 	 } 
 
 	 	 i n t     p o p   ( ) / / ���Q�R  
 
 	 	 { 
 
 	 	 	 p I n + + ; 
 
 	 	 	 r e t u r n   p I n ; 
 
 	 	 } 
 
 	 	 b o o l   i s E m p t y ( ) / / $R�e�R/f&T:Nzz  
 
 	 	 { 
 
 	 	 	 i f   ( p I n > p O u t )   r e t u r n   t r u e ; 
 
 	 	 	 r e t u r n   f a l s e ; 
 
 	 	 } 
 
 	 	 n o d e   g e t N o d e ( i n t   e ) / / ���Se ُ*Npe�~MOn
N�vn o d e �v^ԏ�V  
 
 	 	 { 
 
 	 	 	 r e t u r n   q u e u e [ e ] ; 
 
 	 	 } 
 
 	 	 v o i d   t r a n s f o r m ( i n t   e ) / / �N�~�p�R_�V�n0Rw��pMOn��[~beg�e�v_  
 
 	 	 { 
 
 	 	 	 / / c o u t < < e < < e n d l ; 
 
 	 	 	 i f   ( 0 = = e )   r e t u r n   ; / / �Y�g0R�Nw��pR ��Q  
 
 	 	 	 t r a n s f o r m ( q u e u e [ e ] . p r e ) ; / / �R_�[~b_  
 
 	 	 	 b e s t . p u s h ( q u e u e [ e ] . x , q u e u e [ e ] . y ) ; / / �ReQ0Rh-N  
 
 	 	 	 
 
 	 	 } 
 
 	 	 S t a c k   t o S t a c k ( n o d e   t e m p ) / / \�Rl�S:Nh  
 
 	 	 { 
 
 	 	 	 
 
 	 	 	 t r a n s f o r m ( t e m p . p r e ) ; / / �Y
N  
 
 	 	 	 b e s t . p u s h ( t e m p . x , t e m p . y ) ; / / �ReQ�~�peQh  
 
 	 	 / / 	 b e s t . o u t S t a c k ( ) ;   
 
 	 	 	 r e t u r n   b e s t ; 
 
 	 	 	 
 
 	 	 } 
 
 	 	 
 
 }   ; 
 
 c l a s s   M y M a z e   :   p u b l i c   M a z e 
 
 { 
 
 	 p r i v a t e   : 
 
 	 	 Q u e u e   q e ; 
 
 	 	 b o o l   u s e d [ 2 0 0 ] [ 2 0 0 ] ; / / $R�ep�Ǐ�v��1\
Np��N  
 
 	 p u b l i c : 
 
 	 	 b o o l   i s U s e d ( n o d e   t e m p ) 
 
 	 	 { 
 
 	 	 	 r e t u r n   u s e d [ t e m p . x ] [ t e m p . y ] ; 
 
 	 	 } 
 
 	 	 v o i d   s e t U s e d ( n o d e   t e m p ) 
 
 	 	 { 
 
 	 	 	 u s e d [ t e m p . x ] [ t e m p . y ] = t r u e ; 
 
 	 	 } 
 
 	 	 b o o l   i s N o d e C a n ( n o d e   t e m p ) / / $R�e/f&T�SL�  
 
 	 	 { 
 
 	 	 	 i f   ( c a n ( t e m p . x , t e m p . y ) & & ! i s U s e d ( t e m p ) )   r e t u r n   t r u e ; 
 
 	 	 	 r e t u r n   f a l s e ; 
 
 	 	 } 
 
 	 	 b o o l   i s N o d e O u t ( n o d e   t e m p ) / / $R�e/f&T:N�Q�S  
 
 	 	 { 
 
 	 	 	 r e t u r n   i s O u t ( t e m p . x , t e m p . y ) ; 
 
 	 	 } 
 
 	 	 v o i d   B F S ( ) 
 
 	 	 { 
 
 	 	 	 
 
 	 	 	 i n t   d x [ 4 ] = { 1 , 0 , 0 , - 1 } ; / / �VE��`�O�V*N�eT� N�[��t��nZi  
 
 	 	 	 i n t   d y [ 4 ] = { 0 , 1 , - 1 , 0 } ; 
 
 	 	 	 i n t   i , p ;   
 
 	 	 	 n o d e   t e m p ; 
 
 	 	 	 q e . p u s h ( g e t M o u s e X ( ) , g e t M o u s e Y ( ) , 0 , 0 ) ; / / \w��p�ReQ0R�R  
 
 	 	 	 w h i l e   ( ! q e . i s E m p t y ( ) ) / / S_�R
N:Nzz�e��`�`�NHN�eP:Nzz  
 
 	 	 	 { 
 
 	 	 	 	 p =   q e . p o p ( ) ; / / ���S ���ibU\�v���p  
 
 	 	 	 	 f o r   ( i = 0 ; i < 4 ; i + + ) / / �g>N㉳Q��v@b	g�e�l  
 
 	 	 	 	 { 
 
 	 	 	 	 	 t e m p = q e . g e t N o d e ( p ) ; / / \Ջp� NN  
 
 	 	 	 	 	 t e m p . x = t e m p . x + d x [ i ] ; 
 
 	 	 	 	 	 t e m p . y = t e m p . y + d y [ i ] ; 
 
 	 	 	 	 	 
 
 	 	 	 	 	 i f   ( i s N o d e C a n ( t e m p ) ) / / $R�e/f&T�SL�  
 
 	 	 	 	 	 { 
 
 	 	 	 	 	 	 s e t U s e d ( t e m p ) ; / / �SL�Rh��:Np�Ǐ�N  
 
 	 	 	 	 	 	 t e m p . p r e = p ; / / ��U_N/f�T*N�pp�0Rُ*N�p�v  
 
 	 	 	 	 	 	 t e m p . s t e p + + ; / / ekpe�R N  
 
 	 	 	 	 	 	 q e . p u s h ( t e m p ) ; / / �ReQ0R�R  
 
 	 	 	 	 	 	 i f   ( i s N o d e O u t ( t e m p ) ) / / $R�e/f&T0R�Q�S�N  
 
 	 	 	 	 	 	 { 
 
 	 	 	 	 	 	 	 / / ^�^OHQd"}N�m�^
NT�~b0R�Q�S�_6q/f g�w�v���`�`:N�NHN	�  
 
 	 	 	 	 	 	 	 c o u t < < t e m p . s t e p < < e n d l ; 
 
 	 	 	 	 	 	 	 b e g i n P a t h ( q e . t o S t a c k ( t e m p ) ) ; / / ���Q�T�N~b�v��'T�  
 
 	 	 	 	 	 	 } 
 
 	 	 	 	 	 } 
 
 	 	 	 	 } 
 
 	 	 	 } 
 
 	 	 } 
 
 } ; 
 
 / * 
 
 * �e�X�Q�[�~_g  
 
 * / 
 
 i n t   m a i n ( ) { 
 
 	 M y M a z e   * m a z e = n e w   M y M a z e ( ) ; / / �e�^*N���[  
 
 	 m a z e - > l o a d M a p F r o m F i l e ( " m a p . t x t " ) ; / / ���S0W�V  
 
 	 m a z e - > s e t N a m e ( " S a b r i n a " ) ; 
 
 	 m a z e - > B F S ( ) ; 
 
 	 r e t u r n   0 ; 
 
 } 
 
 
