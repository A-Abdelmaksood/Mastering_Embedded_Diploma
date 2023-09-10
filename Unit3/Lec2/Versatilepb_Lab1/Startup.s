/* Learn-in-depth 
   write code from scratch
   Eng.Ahmed_Elsayed
*/

.global reset 
reset:
	  ldr sp, =Stack_Top
	  bl main
stop: b stop