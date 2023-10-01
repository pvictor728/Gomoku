		#include <stdio.h>
		#include <string.h>
		#include <ctype.h>
		#include <stdlib.h>
		#include "jogadores.h"
		#include "tela.h"



// verificando a validade das rodadas de acordo com a segunda regra do ninuki
int verifique_validade_jogada(int n, char **matriz, int i, int j){
	int cont_l = 0 , cont_c = 0 , cont_dp = 0 , cont_ds = 0 , cont;
	int l_ext_1[2] = {i,j} , l_ext_2[2] = {i,j} , c_ext_1[2] = {i,j} , c_ext_2[2] = {i,j} , dp_ext_1[2] = {i,j} , dp_ext_2[2] = {i,j} , ds_ext_1[2] = {i,j} , ds_ext_2[2] = {i,j};

		//////////////////////////////////////////////////////////////////////COLUNAS//////////////////////////////////////////////////////////////////////

	if(cont_c <= 2){
			cont_l = 0;
			cont_c = 0; 
			cont_dp = 0;
			cont_ds = 0;
		if(i != 0){//Para cima
			
				  	
			for(cont = 1; cont < 3; cont++){
				
				if( ((i - cont) >= 0) && ((i - cont) < n) &&
				  	matriz[i - cont][j] == matriz[i][j] && matriz[i - cont][j] != '-'){			  		
				  	c_ext_1[0] = i - cont;
				  	c_ext_1[1] = j;
				  	cont_c = cont_c + 1;
				}
				else{
				  break;
				}
			}
		}
		if(i != n-1){// Para baixo

			for(cont = 1; cont < 3; cont++){
				
				if( ((i + cont) >= 0) && ((i + cont) < n) &&
					matriz[i + cont][j] == matriz[i][j] && matriz[i + cont][j] != '-'){				  	
				  	c_ext_2[0] = i + cont;
				  	c_ext_2[1] = j;
				  	cont_c = cont_c + 1;
				}
				else{
				 break;
				}
			}
		}
	}

		//////////////////////////////////////////////////////////////////////BUSCA DA FORMAÇÃO 3x3//////////////////////////////////////////////////////////////////////

	if(cont_c >= 2){
		
		//////////////////////////////////////////////////////////////////////LINHA PRIMEIRA EXTREMIDADE//////////////////////////////////////////////////////////////////////

		if(cont_l <= 2){
					
			if(c_ext_1[1] != 0 ){// Para esquerda
				cont_l = 0;
				
				for(cont = 1; cont < 3; cont++){
				
					if( ((c_ext_1[1] - cont) >= 0) && ((c_ext_1[1] - cont) < n) &&
						matriz[c_ext_1[0]][c_ext_1[1] - cont] == matriz[c_ext_1[0]][c_ext_1[1]] && matriz[c_ext_1[0]][c_ext_1[1] - cont] != '-'){					
						cont_l = cont_l + 1;
					}
					else{
				 	break;
					}
				}
				
				if(cont_l >= 2){
					return 1;
				}
			}
			if(c_ext_1[1] != n-1){// Para direita
				cont_l = 0;
				
				for(cont = 1; cont < 3; cont++){
					
					if( ((c_ext_1[1] + cont) >= 0) && ((c_ext_1[1] + cont) < n) &&
						matriz[c_ext_1[0]][c_ext_1[1] + cont] == matriz[c_ext_1[0]][c_ext_1[1]] && matriz[c_ext_1[0]][c_ext_1[1] + cont] != '-'){					
						cont_l = cont_l + 1;
					}
					else{
				 	break;
					}
				}
				
				if(cont_l >= 2){
					return 1;
				}
			}
		}

		//////////////////////////////////////////////////////////////////////LINHA SEGUNDA EXTREMIDADE//////////////////////////////////////////////////////////////////////

		if(cont_l <= 2){
			
						
			if(c_ext_2[1] != 0 ){// Para esquerda
				cont_l = 0;
				
				for(cont = 1; cont < 3; cont++){
				
					if( ((c_ext_2[1] - cont) >= 0) && ((c_ext_2[1] - cont) < n) &&
						matriz[c_ext_2[0]][c_ext_2[1] - cont] == matriz[c_ext_2[0]][c_ext_2[1]] && matriz[c_ext_2[0]][c_ext_2[1] - cont] != '-'){					
						cont_l = cont_l + 1;
					}
					else{
				 	break;
					}
				}
				
				if(cont_l >= 2){
					return 1;
				}
			}
			if(c_ext_2[1] != n-1){// Para direita
				cont_l = 0;
				
				for(cont = 1; cont < 3; cont++){
					
					if( ((c_ext_2[1] + cont) >= 0) && ((c_ext_2[1] + cont) < n) &&
						matriz[c_ext_2[0]][c_ext_2[1] + cont] == matriz[c_ext_2[0]][c_ext_2[1]] && matriz[c_ext_2[0]][c_ext_2[1] + cont] != '-'){					
						cont_l = cont_l + 1;
					}
					else{
				 	break;
					}
				}
				
				if(cont_l >= 2){
					return 1;
				}
			}
		}


		//////////////////////////////////////////////////////////////////////DIAGONAL PRINCIPAL  PRIMEIRA EXTREMIDADE//////////////////////////////////////////////////////////////////////

		if(cont_dp <= 2){
			
			if(c_ext_1[0] != 0){//para cima
				cont_dp = 0;
					
				for(cont = 1; cont < 3; cont++){
						
					if( ((c_ext_1[0] - cont) >= 0) && ((c_ext_1[0] - cont) < n) &&
						((c_ext_1[1] - cont) >= 0) && ((c_ext_1[1] - cont) < n) &&
						matriz[c_ext_1[0] - cont][c_ext_1[1] - cont] == matriz[c_ext_1[0]][c_ext_1[1]] && matriz[c_ext_1[0] - cont][c_ext_1[1] - cont] != '-'){
						cont_dp = cont_dp +1;
					}
					else{
				 	break;
					}
				}
				
				if(cont_dp >= 2){
					return 1;
				}
			}
			if(c_ext_1[0] != n-1){
					cont_dp = 0;
				for(cont = 1; cont < 3; cont++){//para baixo
					
							
					if( ((c_ext_1[0] + cont) >= 0) && ((c_ext_1[0] + cont) < n) &&
						((c_ext_1[1] + cont) >= 0) && ((c_ext_1[1] + cont) < n) &&
						matriz[c_ext_1[0] + cont][c_ext_1[1] + cont] == matriz[c_ext_1[0]][c_ext_1[1]] && matriz[c_ext_1[0] + cont][c_ext_1[1] + cont] != '-'){						
						cont_dp = cont_dp +1;
					}
					else{
					 break;
					}
				}
				
				if(cont_dp >= 2){
					return 1;
				}
			}
		}

		//////////////////////////////////////////////////////////////////////DIAGONAL PRINCIPAL SEGUNDA EXTREMIDADE//////////////////////////////////////////////////////////////////////

		if(cont_dp <= 2){
			
			if(c_ext_2[0] != 0){//para cima
				cont_dp = 0;
					
				for(cont = 1; cont < 3; cont++){
						
					if( ((c_ext_2[0] - cont) >= 0) && ((c_ext_2[0] - cont) < n) &&
						((c_ext_2[1] - cont) >= 0) && ((c_ext_2[1] - cont) < n) &&
						matriz[c_ext_2[0] - cont][c_ext_2[1] - cont] == matriz[c_ext_2[0]][c_ext_2[1]] && matriz[c_ext_2[0] - cont][c_ext_2[1] - cont] != '-'){						
						cont_dp = cont_dp +1;
					}
					else{
				 	break;
					}
				}
			
				if (cont_dp >= 2){
					return 1;
				}
			}
			if(c_ext_2[0] != n-1){
					cont_dp = 0;
				for(cont = 1; cont < 3; cont++){//para baixo

							
					if( ((c_ext_2[0] + cont) >= 0) && ((c_ext_2[0] + cont) < n) &&
						((c_ext_2[1] + cont) >= 0) && ((c_ext_2[1] + cont) < n) &&
						matriz[c_ext_2[0] + cont][c_ext_2[1] + cont] == matriz[c_ext_2[0]][c_ext_2[1]] && matriz[c_ext_2[0] + cont][c_ext_2[1] + cont] != '-'){
						cont_dp = cont_dp +1;
					}
					else{
					 break;
					}
				}
				
				if(cont_dp >= 2){
					return 1;
				}
			}
		}

		//////////////////////////////////////////////////////////////////////DIAGONAL SECUNDARIA PRIMEIRA EXTREMIDADE//////////////////////////////////////////////////////////////////////

		if(cont_ds <= 2){
				
				if (c_ext_1[0] != 0){//Para cima
					cont_ds = 0;

					for(cont = 1; cont < 3; cont++){
					    		
						if( ((c_ext_1[0] - cont) >= 0) && ((c_ext_1[0] - cont) < n) &&
						    ((c_ext_1[1] + cont) >= 0) && ((c_ext_1[1] + cont) < n) &&
					    	matriz[c_ext_1[0] - cont][c_ext_1[1] + cont] == matriz[c_ext_1[0]][c_ext_1[1]] && matriz[c_ext_1[0] - cont][c_ext_1[1] + cont] != '-'){					    
					    	cont_ds = cont_ds + 1;
						}
						else{
					 	break;
						}
					}
					
					if(cont_ds >= 2){
						return 1;
					}
				}
				if (c_ext_1[0] != n-1){//Para baixo
					cont_ds = 0;
					    	
					for(cont = 1; cont < 3; cont++){
					    		
						if( ((c_ext_1[0] + cont) >= 0) && ((c_ext_1[0] + cont) < n) &&
					    	((c_ext_1[1] - cont) >= 0) && ((c_ext_1[1] - cont) < n) &&
					    	matriz[c_ext_1[0] + cont][c_ext_1[1] - cont] == matriz[c_ext_1[0]][c_ext_1[1]] && matriz[c_ext_1[0] + cont][c_ext_1[1] - cont] != '-') {					    					    	
					    	cont_ds = cont_ds + 1;
						}
						else{
					 	break;
						}
					}
					
					if (cont_ds >= 2){
						return 1;
					}
				}
		}

				//////////////////////////////////////////////////////////////////////DIAGONAL SECUNDARIA SEGUNDA EXTREMIDADE//////////////////////////////////////////////////////////////////////

		if(cont_ds <= 2){
				
				if (c_ext_2[0] != 0){//Para cima
						cont_ds = 0;
					
					for(cont = 1; cont < 3; cont++){
					    		
						if( ((c_ext_2[0] - cont) >= 0) && ((c_ext_2[0] - cont) < n) &&
						    ((c_ext_2[1] + cont) >= 0) && ((c_ext_2[1] + cont) < n) &&
					    	matriz[c_ext_2[0] - cont][c_ext_2[1] + cont] == matriz[c_ext_2[0]][c_ext_2[1]] && matriz[c_ext_2[0] - cont][c_ext_2[1] + cont] != '-'){					    
					    	cont_ds = cont_ds + 1;
						}
						else{
					 	break;
						}
					}
					
					if(cont_ds >= 2){
						return 1;
					}
				}
				if (c_ext_2[0] != n-1){//Para baixo
					cont_ds = 0;
					    	
					for(cont = 1; cont < 3; cont++){
					    		
						if( ((c_ext_2[0] + cont) >= 0) && ((c_ext_2[0] + cont) < n) &&
					    	((c_ext_2[1] - cont) >= 0) && ((c_ext_2[1] - cont) < n) &&
					    	matriz[c_ext_2[0] + cont][c_ext_2[1] - cont] == matriz[c_ext_2[0]][c_ext_2[1]] && matriz[c_ext_2[0] + cont][c_ext_2[1] - cont] != '-') {					    					    	
					    	cont_ds = cont_ds + 1;
						}
						else{
					 	break;
						}
					}
					
					if (cont_ds >= 2){
						return 1;
					}
				}
		}

	}
			//////////////////////////////////////////////////////////////////////LINHAS//////////////////////////////////////////////////////////////////////

	if(cont_l <= 2){
		cont_l = 0;
		cont_c = 0; 
		cont_dp = 0;
		cont_ds = 0;
						
		if(j != 0 ){// Para esquerda

				
			for(cont = 1; cont < 3; cont++){
				
				if( ((j - cont) >= 0) && ((j - cont) < n) &&
					matriz[i][j - cont] == matriz[i][j] && matriz[i][j - cont] != '-'){					
					l_ext_1[0] = i;
					l_ext_1[1] = j - cont;
					cont_l = cont_l + 1;
				}
				else{
				break;
				}
			}
		}
		if(j != n-1){// Para direita
				
			for(cont = 1; cont < 3; cont++){
					
				if( ((j + cont) >= 0) && ((j + cont) < n) &&
					matriz[i][j + cont] == matriz[i][j] && matriz[i][j + cont] != '-'){					
					l_ext_2[0] = i;
					l_ext_2[1] = j + cont;
					cont_l = cont_l + 1;
				}
				else{
				break;
				}
			}
		}
	}


		//////////////////////////////////////////////////////////////////////BUSCA DA FORMAÇÃO 3x3//////////////////////////////////////////////////////////////////////

	if(cont_l >= 2){

		//////////////////////////////////////////////////////////////////////COLUNA PRIMEIRA EXTREMIDADE//////////////////////////////////////////////////////////////////////

		if(cont_c <= 2){
				
			if(l_ext_1[0] != 0){//Para cima
				cont_c = 0;
				  	
				for(cont = 1; cont < 3; cont++){
				
					if( ((l_ext_1[0] - cont) >= 0) && ((l_ext_1[0] - cont) < n) &&
				  		matriz[l_ext_1[0] - cont][l_ext_1[1]] == matriz[l_ext_1[0]][l_ext_1[1]] && matriz[l_ext_1[0] - cont][l_ext_1[1]] != '-'){			  						  		
				  		cont_c = cont_c + 1;
					}
					else{
				  	break;
					}
				}
				
				if(cont_c >= 2){
					return 1;
				}
			}

			if(l_ext_1[0] != n-1){// Para baixo
				cont_c = 0;

				for(cont = 1; cont < 3; cont++){
				
					if( ((l_ext_1[0] + cont) >= 0) && ((l_ext_1[0] + cont) < n) &&
						matriz[l_ext_1[0] + cont][l_ext_1[1]] == matriz[l_ext_1[0]][l_ext_1[1]] && matriz[l_ext_1[0] + cont][l_ext_1[1]] != '-'){				  					  		
				  		cont_c = cont_c + 1;
					}
					else{
				 	break;
					}
				}
				
				if(cont_c >= 2){
					return 1;
				}
			}
		}

		//////////////////////////////////////////////////////////////////////COLUNA SEGUNDA EXTREMIDADE//////////////////////////////////////////////////////////////////////

		if(cont_c <= 2){
				
			if(l_ext_2[0] != 0){//Para cima
				cont_c = 0;
				  	
				for(cont = 1; cont < 3; cont++){
				
					if( ((l_ext_2[0] - cont) >= 0) && ((l_ext_2[0] - cont) < n) &&
				  		matriz[l_ext_2[0] - cont][l_ext_2[1]] == matriz[l_ext_2[0]][l_ext_2[1]] && matriz[l_ext_2[0] - cont][l_ext_2[1]] != '-'){			  						  		
				  		cont_c = cont_c + 1;
					}
					else{
				  	break;
					}
				}
				
				if(cont_c >= 2){
					return 1;
				}
			}

			if(l_ext_2[0] != n-1){// Para baixo
				cont_c = 0;

				for(cont = 1; cont < 3; cont++){
				
					if( ((l_ext_2[0] + cont) >= 0) && ((l_ext_2[0] + cont) < n) &&
						matriz[l_ext_2[0] + cont][l_ext_2[1]] == matriz[l_ext_2[0]][l_ext_2[1]] && matriz[l_ext_2[0] + cont][l_ext_2[1]] != '-'){				  					  		
				  		cont_c = cont_c + 1;
					}
					else{
				 	break;
					}
				}
				
				if(cont_c >= 2){
					return 1;
				}
			}
		}

		//////////////////////////////////////////////////////////////////////DIAGONAL PRINCIPAL PRIMEIRA EXTREMIDADE//////////////////////////////////////////////////////////////////////

		if(cont_dp <= 2){
				
			if(l_ext_1[0] != 0){//para cima
				cont_dp = 0;
					
				for(cont = 1; cont < 3; cont++){
						
					if( ((l_ext_1[0] - cont) >= 0) && ((l_ext_1[0] - cont) < n) &&
						((l_ext_1[1] - cont) >= 0) && ((l_ext_1[1] - cont) < n) &&
						matriz[l_ext_1[0] - cont][l_ext_1[1] - cont] == matriz[l_ext_1[0]][l_ext_1[1]] && matriz[l_ext_1[0] - cont][l_ext_1[1] - cont] != '-'){
						cont_dp = cont_dp +1;
					}
					else{
				 	break;
					}
				}
				
				if(cont_dp >= 2){
					return 1;
				}
			}
			if(l_ext_1[0] != n-1){
						cont_dp = 0;
				for(cont = 1; cont < 3; cont++){//para baixo
							
					if( ((l_ext_1[0] + cont) >= 0) && ((l_ext_1[0] + cont) < n) &&
						((l_ext_1[1] + cont) >= 0) && ((l_ext_1[1] + cont) < n) &&
						matriz[l_ext_1[0] + cont][l_ext_1[1] + cont] == matriz[l_ext_1[0]][l_ext_1[1]] && matriz[l_ext_1[0] + cont][l_ext_1[1] + cont] != '-'){						
						cont_dp = cont_dp +1;
					}
					else{
					 break;
					}
				}
				
				if(cont_dp >= 2){
					return 1;
				}
			}
		}

		//////////////////////////////////////////////////////////////////////DIAGONAL PRINCIPAL SEGUNDA EXTREMIDADE//////////////////////////////////////////////////////////////////////

		if(cont_dp <= 2){
				
			if(l_ext_2[0] != 0){//para cima
				cont_dp = 0;
					
				for(cont = 1; cont < 3; cont++){
						
					if( ((l_ext_2[0] - cont) >= 0) && ((l_ext_2[0] - cont) < n) &&
						((l_ext_2[1] - cont) >= 0) && ((l_ext_2[1] - cont) < n) &&
						matriz[l_ext_2[0] - cont][l_ext_2[1] - cont] == matriz[l_ext_2[0]][l_ext_2[1]] && matriz[l_ext_2[0] - cont][l_ext_2[1] - cont] != '-'){						
						cont_dp = cont_dp +1;
					}
					else{
				 	break;
					}
				}
				
				if (cont_dp >= 2){
					return 1;
				}
			}
			if(l_ext_2[0] != n-1){
				cont_dp = 0;
						
				for(cont = 1; cont < 3; cont++){//para baixo
							
					if( ((l_ext_2[0] + cont) >= 0) && ((l_ext_2[0] + cont) < n) &&
						((l_ext_2[1] + cont) >= 0) && ((l_ext_2[1] + cont) < n) &&
						matriz[l_ext_2[0] + cont][l_ext_2[1] + cont] == matriz[l_ext_2[0]][l_ext_2[1]] && matriz[l_ext_2[0] + cont][l_ext_2[1] + cont] != '-'){
						cont_dp = cont_dp +1;
					}
					else{
					 break;
					}
				}
				
				if(cont_dp >= 2){
					return 1;
				}
			}
		}

		//////////////////////////////////////////////////////////////////////DIAGONAL SECUNDARIA PRIMEIRA EXTREMIDADE//////////////////////////////////////////////////////////////////////

		if(cont_ds <= 2){
				
				if (l_ext_1[0] != 0){//Para cima
					cont_ds = 0;
					
					for(cont = 1; cont < 3; cont++){
					    		
						if( ((l_ext_1[0] - cont) >= 0) && ((l_ext_1[0] - cont) < n) &&
						    ((l_ext_1[1] + cont) >= 0) && ((l_ext_1[1] + cont) < n) &&
					    	matriz[l_ext_1[0] - cont][l_ext_1[1] + cont] == matriz[l_ext_1[0]][l_ext_1[1]] && matriz[l_ext_1[0] - cont][l_ext_1[1] + cont] != '-'){					    
					    	cont_ds = cont_ds + 1;
						}
						else{
					 	break;
						}
					}
					if(cont_ds >= 2){
						return 1;
					}
				}
				
				if (l_ext_1[0] != n-1){//Para baixo
					cont_ds = 0;
					    	
					for(cont = 1; cont < 3; cont++){
					    		
						if( ((l_ext_1[0] + cont) >= 0) && ((l_ext_1[0] + cont) < n) &&
					    	((l_ext_1[1] - cont) >= 0) && ((l_ext_1[1] - cont) < n) &&
					    	matriz[l_ext_1[0] + cont][l_ext_1[1] - cont] == matriz[l_ext_1[0]][l_ext_1[1]] && matriz[l_ext_1[0] + cont][l_ext_1[1] - cont] != '-') {					    					    	
					    	cont_ds = cont_ds + 1;
						}
						else{
					 	break;
						}
					}
					
					if (cont_ds >= 2){
						return 1;
					}
				}
		}

				//////////////////////////////////////////////////////////////////////DIAGONAL SECUNDARIA SEGUNDA EXTREMIDADE//////////////////////////////////////////////////////////////////////

		if(cont_ds <= 2){
			
				
				if (l_ext_2[0] != 0){//Para cima
					cont_ds = 0;
					
					for(cont = 1; cont < 3; cont++){
					    		
						if( ((l_ext_2[0] - cont) >= 0) && ((l_ext_2[0] - cont) < n) &&
						    ((l_ext_2[1] + cont) >= 0) && ((l_ext_2[1] + cont) < n) &&
					    	matriz[l_ext_2[0] - cont][l_ext_2[1] + cont] == matriz[l_ext_2[0]][l_ext_2[1]] && matriz[l_ext_2[0] - cont][l_ext_2[1] + cont] != '-'){					    
					    	cont_ds = cont_ds + 1;
						}
						else{
					 	break;
						}
					}
					
					if(cont_ds >= 2){
						return 1;
					}
				}
				if (l_ext_2[0] != n-1){//Para baixo
					cont_ds = 0;
					    	
					for(cont = 1; cont < 3; cont++){
					    		
						if( ((l_ext_2[0] + cont) >= 0) && ((l_ext_2[0] + cont) < n) &&
					    	((l_ext_2[1] - cont) >= 0) && ((l_ext_2[1] - cont) < n) &&
					    	matriz[l_ext_2[0] + cont][l_ext_2[1] - cont] == matriz[l_ext_2[0]][l_ext_2[1]] && matriz[l_ext_2[0] + cont][l_ext_2[1] - cont] != '-') {					    					    	
					    	cont_ds = cont_ds + 1;
						}
						else{
					 	break;
						}
					}
					
					if (cont_ds >= 2){
						return 1;
					}
				}
		}


	}	

		//////////////////////////////////////////////////////////////////////DIAGONAL PRINCIPAL//////////////////////////////////////////////////////////////////////

	if(cont_dp <= 2){
			cont_l = 0;
			cont_c = 0; 
			cont_dp = 0;
			cont_ds = 0;
			
		if(i != 0){//para cima

					
			for(cont = 1; cont < 3; cont++){
						
				if( ((i - cont) >= 0) && ((i - cont) < n) &&
					((j - cont) >= 0) && ((j - cont) < n) &&
					matriz[i - cont][j - cont] == matriz[i][j] && matriz[i - cont][j - cont] != '-'){
					dp_ext_1[0] = i - cont;
					dp_ext_1[1] = j - cont;
					cont_dp = cont_dp +1;
				}
				else{
				 break;
				}
			}
		}
		if(i != n-1){
					
			for(cont = 1; cont < 3; cont++){//para baixo
						
				if( ((i + cont) >= 0) && ((i + cont) < n) &&
					((j + cont) >= 0) && ((j + cont) < n) &&
					matriz[i + cont][j + cont] == matriz[i][j] && matriz[i + cont][j + cont] != '-'){
					dp_ext_2[0] = i + cont;
					dp_ext_2[1] = j + cont;
					cont_dp = cont_dp +1;
				}
				else{
				 break;
				}
			}
		}
	}

		//////////////////////////////////////////////////////////////////////BUSCA DA FORMAÇÃO 3x3//////////////////////////////////////////////////////////////////////


	if(cont_dp >= 2){

			//////////////////////////////////////////////////////////////////////LINHA PRIMEIRA EXTREMIDADE//////////////////////////////////////////////////////////////////////

		if(cont_l <= 2){
			
						
			if(dp_ext_1[1] != 0 ){// Para esquerda
				cont_l = 0;
				
				for(cont = 1; cont < 3; cont++){
				
					if( ((dp_ext_1[1] - cont) >= 0) && ((dp_ext_1[1] - cont) < n) &&
						matriz[dp_ext_1[0]][dp_ext_1[1] - cont] == matriz[dp_ext_1[0]][dp_ext_1[1]] && matriz[dp_ext_1[0]][dp_ext_1[1] - cont] != '-'){					
						cont_l = cont_l + 1;
					}
					else{
				 	break;
					}
				}
				
				if(cont_l >= 2){
					return 1;
				}
			}
			if(dp_ext_1[1] != n-1){// Para direita
				cont_l = 0;
				
				for(cont = 1; cont < 3; cont++){
					
					if( ((dp_ext_1[1] + cont) >= 0) && ((dp_ext_1[1] + cont) < n) &&
						matriz[dp_ext_1[0]][dp_ext_1[1] + cont] == matriz[dp_ext_1[0]][dp_ext_1[1]] && matriz[dp_ext_1[0]][dp_ext_1[1] + cont] != '-'){					
						cont_l = cont_l + 1;
					}
					else{
				 	break;
					}
				}
				
				if(cont_l >= 2){
					return 1;
				}
			}
		}

		//////////////////////////////////////////////////////////////////////LINHA SEGUNDA EXTREMIDADE//////////////////////////////////////////////////////////////////////

		if(cont_l <= 2){
			
						
			if(dp_ext_2[1] != 0 ){// Para esquerda
				cont_l = 0;
				
				for(cont = 1; cont < 3; cont++){
				
					if( ((dp_ext_2[1] - cont) >= 0) && ((dp_ext_2[1] - cont) < n) &&
						matriz[dp_ext_2[0]][dp_ext_2[1] - cont] == matriz[dp_ext_2[0]][dp_ext_2[1]] && matriz[dp_ext_2[0]][dp_ext_2[1] - cont] != '-'){					
						cont_l = cont_l + 1;
					}
					else{
				 	break;
					}
				}
				if(cont_l >= 2){
					return 1;
				}
			}
			if(dp_ext_2[1] != n-1){// Para direita
				cont_l = 0;
				
				for(cont = 1; cont < 3; cont++){
					
					if( ((dp_ext_2[1] + cont) >= 0) && ((dp_ext_2[1] + cont) < n) &&
						matriz[dp_ext_2[0]][dp_ext_2[1] + cont] == matriz[dp_ext_2[0]][dp_ext_2[1]] && matriz[dp_ext_2[0]][dp_ext_2[1] + cont] != '-'){					
						cont_l = cont_l + 1;
					}
					else{
				 	break;
					}
				}
				
				if(cont_l >= 2){
					return 1;
				}
			}
		}

		//////////////////////////////////////////////////////////////////////COLUNA PRIMEIRA EXTREMIDADE//////////////////////////////////////////////////////////////////////

		if(cont_c <= 2){
				
			if(dp_ext_1[0] != 0){//Para cima
				cont_c = 0;
				  	
				for(cont = 1; cont < 3; cont++){
				
					if( ((dp_ext_1[0] - cont) >= 0) && ((dp_ext_1[0] - cont) < n) &&
				  		matriz[dp_ext_1[0] - cont][dp_ext_1[1]] == matriz[dp_ext_1[0]][dp_ext_1[1]] && matriz[dp_ext_1[0] - cont][dp_ext_1[1]] != '-'){			  						  		
				  		cont_c = cont_c + 1;
					}
					else{
				  	break;
					}
				}
				
				if(cont_c >= 2){
					return 1;
				}
			}

			if(dp_ext_1[0] != n-1){// Para baixo
				cont_c = 0;

				for(cont = 1; cont < 3; cont++){
				
					if( ((dp_ext_1[0] + cont) >= 0) && ((dp_ext_1[0] + cont) < n) &&
						matriz[dp_ext_1[0] + cont][dp_ext_1[1]] == matriz[dp_ext_1[0]][dp_ext_1[1]] && matriz[dp_ext_1[0] + cont][dp_ext_1[1]] != '-'){				  					  		
				  		cont_c = cont_c + 1;
					}
					else{
				 	break;
					}
				}
				
				if(cont_c >= 2){
					return 1;
				}
			}
		}

		//////////////////////////////////////////////////////////////////////COLUNA SEGUNDA EXTREMIDADE//////////////////////////////////////////////////////////////////////

		if(cont_c <= 2){
			
			if(dp_ext_2[0] != 0){//Para cima
				cont_c = 0;
				  	
				for(cont = 1; cont < 3; cont++){
				
					if( ((dp_ext_2[0] - cont) >= 0) && ((dp_ext_2[0] - cont) < n) &&
				  		matriz[dp_ext_2[0] - cont][dp_ext_2[1]] == matriz[dp_ext_2[0]][dp_ext_2[1]] && matriz[dp_ext_2[0] - cont][dp_ext_2[1]] != '-'){			  						  		
				  		cont_c = cont_c + 1;
					}
					else{
				  	break;
					}
				}
				
				if(cont_c >= 2){
					return 1;
				}
			}

			if(dp_ext_2[0] != n-1){// Para baixo
				cont_c = 0;

				for(cont = 1; cont < 3; cont++){
				
					if( ((dp_ext_2[0] + cont) >= 0) && ((dp_ext_2[0] + cont) < n) &&
						matriz[dp_ext_2[0] + cont][dp_ext_2[1]] == matriz[dp_ext_2[0]][dp_ext_2[1]] && matriz[dp_ext_2[0] + cont][dp_ext_2[1]] != '-'){				  					  		
				  		cont_c = cont_c + 1;
					}
					else{
				 	break;
					}
				}
				
				if(cont_c >= 2){
					return 1;
				}
			}
		}


		//////////////////////////////////////////////////////////////////////DIAGONAL SECUNDARIA PRIMEIRA EXTREMIDADE//////////////////////////////////////////////////////////////////////

		if(cont_ds <= 2){
			
				if (dp_ext_1[0] != 0){//Para cima
					cont_ds = 0;
					
					for(cont = 1; cont < 3; cont++){
					    		
						if( ((dp_ext_1[0] - cont) >= 0) && ((dp_ext_1[0] - cont) < n) &&
						    ((dp_ext_1[1] + cont) >= 0) && ((dp_ext_1[1] + cont) < n) &&
					    	matriz[dp_ext_1[0] - cont][dp_ext_1[1] + cont] == matriz[dp_ext_1[0]][dp_ext_1[1]] && matriz[dp_ext_1[0] - cont][dp_ext_1[1] + cont] != '-'){					    
					    	cont_ds = cont_ds + 1;
						}
						else{
					 	break;
						}
					}
					
					if(cont_ds >= 2){
						return 1;
					}
				}
				if (dp_ext_1[0] != n-1){//Para baixo
					cont_ds = 0;
					    	
					for(cont = 1; cont < 3; cont++){
					    		
						if( ((dp_ext_1[0] + cont) >= 0) && ((dp_ext_1[0] + cont) < n) &&
					    	((dp_ext_1[1] - cont) >= 0) && ((dp_ext_1[1] - cont) < n) &&
					    	matriz[dp_ext_1[0] + cont][dp_ext_1[1] - cont] == matriz[dp_ext_1[0]][dp_ext_1[1]] && matriz[dp_ext_1[0] + cont][dp_ext_1[1] - cont] != '-') {					    					    	
					    	cont_ds = cont_ds + 1;
						}
						else{
					 	break;
						}
					}
					
					if (cont_ds >= 2){
						return 1;
					}
				}
		}

				//////////////////////////////////////////////////////////////////////DIAGONAL SECUNDARIA SEGUNDA EXTREMIDADE//////////////////////////////////////////////////////////////////////

		if(cont_ds <= 2){
				
				if (dp_ext_2[0] != 0){//Para cima
					cont_ds = 0;

					for(cont = 1; cont < 3; cont++){
					    		
						if( ((dp_ext_2[0] - cont) >= 0) && ((dp_ext_2[0] - cont) < n) &&
						    ((dp_ext_2[1] + cont) >= 0) && ((dp_ext_2[1] + cont) < n) &&
					    	matriz[dp_ext_2[0] - cont][dp_ext_2[1] + cont] == matriz[dp_ext_2[0]][dp_ext_2[1]] && matriz[dp_ext_2[0] - cont][dp_ext_2[1] + cont] != '-'){					    
					    	cont_ds = cont_ds + 1;
						}
						else{
					 	break;
						}
					}
					
					if(cont_ds >= 2){
						return 1;
					}
				}
				if (dp_ext_2[0] != n-1){//Para baixo
					cont_ds = 0;
					    	
					for(cont = 1; cont < 3; cont++){
					    		
						if( ((dp_ext_2[0] + cont) >= 0) && ((dp_ext_2[0] + cont) < n) &&
					    	((dp_ext_2[1] - cont) >= 0) && ((dp_ext_2[1] - cont) < n) &&
					    	matriz[dp_ext_2[0] + cont][dp_ext_2[1] - cont] == matriz[dp_ext_2[0]][dp_ext_2[1]] && matriz[dp_ext_2[0] + cont][dp_ext_2[1] - cont] != '-') {					    					    	
					    	cont_ds = cont_ds + 1;
						}
						else{
					 	break;
						}
					}
					
					if (cont_ds >= 2){
						return 1;
					}
				}
		}
	}	

		//////////////////////////////////////////////////////////////////////DIAGONAL SECUNDÁRIA//////////////////////////////////////////////////////////////////////

	if(cont_ds <= 2){
			cont_l = 0;
			cont_c = 0; 
			cont_dp = 0;
			cont_ds = 0;
			
			if (i != 0){//Para cima
				
				for(cont = 1; cont < 3; cont++){
					    	
					if( ((i - cont) >= 0) && ((i - cont) < n) &&
					    ((j + cont) >= 0) && ((j + cont) < n) &&
					    matriz[i - cont][j + cont] == matriz[i][j] && matriz[i - cont][j + cont] != '-'){
					    ds_ext_1[0] = i - cont;
					    ds_ext_1[1] = j + cont;
					    cont_ds = cont_ds + 1;
					}
					else{
					 break;
					}
				}
			}
			if (i != n-1){//Para baixo
					    
				for(cont = 1; cont < 3; cont++){
					    	
					if( ((i + cont) >= 0) && ((i + cont) < n) &&
					    ((j - cont) >= 0) && ((j - cont) < n) &&
					    matriz[i + cont][j - cont] == matriz[i][j] && matriz[i + cont][j - cont] != '-') {					    
					    ds_ext_2[0] = i + cont;
					    ds_ext_2[1] = j - cont;
					    cont_ds = cont_ds + 1;
					}
					else{
					 break;
					}
				}
			}
	}

		//////////////////////////////////////////////////////////////////////BUSCA DA FORMAÇÃO 3x3//////////////////////////////////////////////////////////////////////

	if(cont_ds >= 2){

		//////////////////////////////////////////////////////////////////////LINHA PRIMEIRA EXTREMIDADE//////////////////////////////////////////////////////////////////////

		if(cont_l <= 2){
			
						
			if(ds_ext_1[1] != 0 ){// Para esquerda
				cont_l = 0;
				
				for(cont = 1; cont < 3; cont++){
				
					if( ((ds_ext_1[1] - cont) >= 0) && ((ds_ext_1[1] - cont) < n) &&
						matriz[ds_ext_1[0]][ds_ext_1[1] - cont] == matriz[ds_ext_1[0]][ds_ext_1[1]] && matriz[ds_ext_1[0]][ds_ext_1[1] - cont] != '-'){					
						cont_l = cont_l + 1;
					}
					else{
				 	break;
					}
				}
				
				if(cont_l >= 2){
					return 1;
				}
			}
			if(ds_ext_1[1] != n-1){// Para direita
				cont_l = 0;
				
				for(cont = 1; cont < 3; cont++){
					
					if( ((ds_ext_1[1] + cont) >= 0) && ((ds_ext_1[1] + cont) < n) &&
						matriz[ds_ext_1[0]][ds_ext_1[1] + cont] == matriz[ds_ext_1[0]][ds_ext_1[1]] && matriz[ds_ext_1[0]][ds_ext_1[1] + cont] != '-'){					
						cont_l = cont_l + 1;
					}
					else{
				 	break;
					}
				}
				
				if(cont_l >= 2){
					return 1;
				}
			}
		}

		//////////////////////////////////////////////////////////////////////LINHA SEGUNDA EXTREMIDADE//////////////////////////////////////////////////////////////////////

		if(cont_l <= 2){
			
						
			if(ds_ext_2[1] != 0 ){// Para esquerda
				cont_l = 0;
				
				for(cont = 1; cont < 3; cont++){
				
					if( ((ds_ext_2[1] - cont) >= 0) && ((ds_ext_2[1] - cont) < n) &&
						matriz[ds_ext_2[0]][ds_ext_2[1] - cont] == matriz[ds_ext_2[0]][ds_ext_2[1]] && matriz[ds_ext_2[0]][ds_ext_2[1] - cont] != '-'){					
						cont_l = cont_l + 1;
					}
					else{
				 	break;
					}
				}
				if(cont_l >= 2){
					return 1;
				}
			}
			if(ds_ext_2[1] != n-1){// Para direita
				cont_l = 0;

				for(cont = 1; cont < 3; cont++){
					
					if( ((ds_ext_2[1] + cont) >= 0) && ((ds_ext_2[1] + cont) < n) &&
						matriz[ds_ext_2[0]][ds_ext_2[1] + cont] == matriz[ds_ext_2[0]][ds_ext_2[1]] && matriz[ds_ext_2[0]][ds_ext_2[1] + cont] != '-'){					
						cont_l = cont_l + 1;
					}
					else{
				 	break;
					}
				}
				
				if(cont_l >= 2){
					return 1;
				}
			}
		}

		//////////////////////////////////////////////////////////////////////COLUNA PRIMEIRA EXTREMIDADE//////////////////////////////////////////////////////////////////////

		if(cont_c <= 2){
			
				  
			if(ds_ext_1[0] != 0){//Para cima
				  	cont_c = 0;

				for(cont = 1; cont < 3; cont++){
				
					if( ((ds_ext_1[0] - cont) >= 0) && ((ds_ext_1[0] - cont) < n) &&
				  		matriz[ds_ext_1[0] - cont][ds_ext_1[1]] == matriz[ds_ext_1[0]][ds_ext_1[1]] && matriz[ds_ext_1[0] - cont][ds_ext_1[1]] != '-'){			  						  		
				  		cont_c = cont_c + 1;
					}
					else{
				  	break;
					}
				}
				
				if(cont_c >= 2){
					return 1;
				}
			}

			if(ds_ext_1[0] != n-1){// Para baixo
				cont_c = 0;

				for(cont = 1; cont < 3; cont++){
				
					if( ((ds_ext_1[0] + cont) >= 0) && ((ds_ext_1[0] + cont) < n) &&
						matriz[ds_ext_1[0] + cont][ds_ext_1[1]] == matriz[ds_ext_1[0]][ds_ext_1[1]] && matriz[ds_ext_1[0] + cont][ds_ext_1[1]] != '-'){				  					  		
				  		cont_c = cont_c + 1;
					}
					else{
				 	break;
					}
				}
				
				if(cont_c >= 2){
					return 1;
				}
			}
		}

		//////////////////////////////////////////////////////////////////////COLUNA SEGUNDA EXTREMIDADE//////////////////////////////////////////////////////////////////////

		if(cont_c <= 2){
				
			if(ds_ext_2[0] != 0){//Para cima
				cont_c = 0;
				  	
				for(cont = 1; cont < 3; cont++){
				
					if( ((ds_ext_2[0] - cont) >= 0) && ((ds_ext_2[0] - cont) < n) &&
				  		matriz[ds_ext_2[0] - cont][ds_ext_2[1]] == matriz[ds_ext_2[0]][ds_ext_2[1]] && matriz[ds_ext_2[0] - cont][ds_ext_2[1]] != '-'){			  						  		
				  		cont_c = cont_c + 1;
					}
					else{
				  	break;
					}
				}
				
				if(cont_c >= 2){
					return 1;
				}
			}

			if(ds_ext_2[0] != n-1){// Para baixo
				cont_c = 0;
				

				for(cont = 1; cont < 3; cont++){
				
					if( ((ds_ext_2[0] + cont) >= 0) && ((ds_ext_2[0] + cont) < n) &&
						matriz[ds_ext_2[0] + cont][ds_ext_2[1]] == matriz[ds_ext_2[0]][ds_ext_2[1]] && matriz[ds_ext_2[0] + cont][ds_ext_2[1]] != '-'){				  					  		
				  		cont_c = cont_c + 1;
					}
					else{
				 	break;
					}
				}
				
				if(cont_c >= 2){
					return 1;
				}
			}
		}


		//////////////////////////////////////////////////////////////////////DIAGONAL PRINCIPAL PRIMEIRA EXTREMIDADE//////////////////////////////////////////////////////////////////////

		if(cont_dp <= 2){
			
				
			if(ds_ext_1[0] != 0){//para cima
				cont_dp = 0;
					
				for(cont = 1; cont < 3; cont++){
						
					if( ((ds_ext_1[0] - cont) >= 0) && ((ds_ext_1[0] - cont) < n) &&
						((ds_ext_1[1] - cont) >= 0) && ((ds_ext_1[1] - cont) < n) &&
						matriz[ds_ext_1[0] - cont][ds_ext_1[1] - cont] == matriz[ds_ext_1[0]][ds_ext_1[1]] && matriz[ds_ext_1[0] - cont][ds_ext_1[1] - cont] != '-'){
						cont_dp = cont_dp +1;
					}
					else{
				 	break;
					}
				}
				
				if(cont_dp >= 2){
					return 1;
				}
			}
			if(ds_ext_1[0] != n-1){
				cont_dp = 0;
						
				for(cont = 1; cont < 3; cont++){//para baixo
							
					if( ((ds_ext_1[0] + cont) >= 0) && ((ds_ext_1[0] + cont) < n) &&
						((ds_ext_1[1] + cont) >= 0) && ((ds_ext_1[1] + cont) < n) &&
						matriz[ds_ext_1[0] + cont][ds_ext_1[1] + cont] == matriz[ds_ext_1[0]][ds_ext_1[1]] && matriz[ds_ext_1[0] + cont][ds_ext_1[1] + cont] != '-'){						
						cont_dp = cont_dp +1;
					}
					else{
					 break;
					}
				}
				
				if(cont_dp >= 2){
					return 1;
				}
			}
		}

		//////////////////////////////////////////////////////////////////////DIAGONAL PRINCIPAL SEGUNDA EXTREMIDADE//////////////////////////////////////////////////////////////////////

		if(cont_dp <= 2){
			
				
			if(ds_ext_2[0] != 0){//para cima
				cont_dp = 0;
					
				for(cont = 1; cont < 3; cont++){
						
					if( ((ds_ext_2[0] - cont) >= 0) && ((ds_ext_2[0] - cont) < n) &&
						((ds_ext_2[1] - cont) >= 0) && ((ds_ext_2[1] - cont) < n) &&
						matriz[ds_ext_2[0] - cont][ds_ext_2[1] - cont] == matriz[ds_ext_2[0]][ds_ext_2[1]] && matriz[ds_ext_2[0] - cont][ds_ext_2[1] - cont] != '-'){						
						cont_dp = cont_dp +1;
					}
					else{
				 	break;
					}
				}
				
				if (cont_dp >= 2){
					return 1;
				}
			}
			if(ds_ext_2[0] != n-1){
				cont_dp = 0;
						
				for(cont = 1; cont < 3; cont++){//para baixo
							
					if( ((ds_ext_2[0] + cont) >= 0) && ((ds_ext_2[0] + cont) < n) &&
						((ds_ext_2[1] + cont) >= 0) && ((ds_ext_2[1] + cont) < n) &&
						matriz[ds_ext_2[0] + cont][ds_ext_2[1] + cont] == matriz[ds_ext_2[0]][ds_ext_2[1]] && matriz[ds_ext_2[0] + cont][ds_ext_2[1] + cont] != '-'){
						cont_dp = cont_dp +1;
					}
					else{
					 break;
					}
				}
				
				if(cont_dp >= 2){
					return 1;
				}
			}
		}
	}
	
	return 0;
}







		//analisa validade da jogada e substitui na matriz
		void atualiza_jogo(char **matriz, int n, jogador gamer){

			int i, j, verifique = 1, validacao;

			do{
				printf("%s informe sua jogada (x y): \n", gamer.nome);
				scanf("%d %d", &i, &j);
		    if((i < n && i >= 0) && (j < n && j >= 0)){
		    	
		    	
		     
		    	if(matriz[i][j] == '-'){


		        

		        	verifique = 0;

		        	if(gamer.cor == 0){
		        		matriz[i][j] = 'W';
		        	}
		        	else if(gamer.cor == 1){
		        		matriz[i][j] = 'B';
		        	}
		        	validacao = verifique_validade_jogada(n, matriz, i, j);
		        	printf("validação = %d\n",validacao);
		        	if(validacao == 1){//quando a jogada ñ eh permitida
		        	printf("Jogada invalida.\nSequencia 3x3 proibida.\n");
		        	matriz[i][j] = '-';
		        	verifique = 1;
		        	}
		    	}
		    	else{
		    	printf("Jogada invalida. \nCasa ocupada.\n");
		    	}
			}
			else{
			printf("Jogada invalida. \n");
			}

			}while(verifique == 1);

			(*gamer.move).x = i;
			(*gamer.move).y = j;
		}



		//funcao para verificar vitoria
		int verifique_vitoria(int n, char **matriz, jogador gamer){
			int cont, cont_l = 0, cont_c = 0, cont_dp = 0, cont_ds = 0;


		  //coluna
		  if((*gamer.move).x != 0){//Para cima
		  	for(cont = 1; cont < 5; cont++){
		  		if( (((*gamer.move).x - cont) >= 0) && (((*gamer.move).x - cont) < n) &&
		  			matriz[(*gamer.move).x - cont][(*gamer.move).y] == matriz[(*gamer.move).x][(*gamer.move).y] && matriz[(*gamer.move).x - cont][(*gamer.move).y] != '-'){
		  			cont_c++;
		  	}
		  	else{
		  		break;
		  	}
		  }
		}
		  if((*gamer.move).x != n-1){// Para baixo
		  	for(cont = 1; cont < 5; cont++){
		  		if( (((*gamer.move).x + cont) >= 0) && (((*gamer.move).x + cont) < n) &&
		  			matriz[(*gamer.move).x + cont][(*gamer.move).y] == matriz[(*gamer.move).x][(*gamer.move).y] && matriz[(*gamer.move).x + cont][(*gamer.move).y] != '-'){
		  			cont_c++;
		  	}
		  	else{
		  		break;
		  	}
		  }
		}
		if(cont_c >= 4){
			return 1;
		}


		  //linha
		if((*gamer.move).y != 0 ){
		  for(cont = 1; cont < 5; cont++){// Para esquerda
		  	if( (((*gamer.move).y - cont) >= 0) && (((*gamer.move).y - cont) < n) &&
		  		matriz[(*gamer.move).x][(*gamer.move).y - cont] == matriz[(*gamer.move).x][(*gamer.move).y] && matriz[(*gamer.move).x][(*gamer.move).y - cont] != '-'){
		  		cont_l++;
		  }
		  else{
		  	break;
		  }
		}
		}
		  if((*gamer.move).y != n-1){// Para direita
		  	for(cont = 1; cont < 5; cont++){
		  		if( (((*gamer.move).y + cont) >= 0) && (((*gamer.move).y + cont) < n) &&
		  			matriz[(*gamer.move).x][(*gamer.move).y + cont] == matriz[(*gamer.move).x][(*gamer.move).y] && matriz[(*gamer.move).x][(*gamer.move).y + cont] != '-'){
		  			cont_l++;
		  	}
		  	else{
		  		break;
		  	}
		  }
		}
		if(cont_l >= 4){
			return 1;
		}



		  //diagonal "principal"
		if((*gamer.move).x != 0){
		  for(cont = 1; cont < 5; cont++){//para cima
		  	if( (((*gamer.move).x - cont) >= 0) && (((*gamer.move).x - cont) < n) &&
		  		(((*gamer.move).y - cont) >= 0) && (((*gamer.move).y - cont) < n) &&
		  		matriz[(*gamer.move).x - cont][(*gamer.move).y - cont] == matriz[(*gamer.move).x][(*gamer.move).y] && matriz[(*gamer.move).x - cont][(*gamer.move).y - cont] != '-'){
		  		cont_dp++;
		  }
		  else{
		  	break;
		  }
		}
		}
		if((*gamer.move).x != n-1){
		  for(cont = 1; cont < 5; cont++){//para baixo
		  	if( (((*gamer.move).x + cont) >= 0) && (((*gamer.move).x + cont) < n) &&
		  		(((*gamer.move).y + cont) >= 0) && (((*gamer.move).y + cont) < n) &&
		  		matriz[(*gamer.move).x + cont][(*gamer.move).y + cont] == matriz[(*gamer.move).x][(*gamer.move).y] && matriz[(*gamer.move).x + cont][(*gamer.move).y + cont] != '-'){
		  		cont_dp++;
		  }
		  else{
		  	break;
		  }
		}
		}
		if(cont_dp >= 4){
			return 1;
		}





		  //diagonal "secundaria"
		if ((*gamer.move).x != 0){
		    for(cont = 1; cont < 5; cont++){//Para cima
		    	if( (((*gamer.move).x - cont) >= 0) && (((*gamer.move).x - cont) < n) &&
		    		(((*gamer.move).y + cont) >= 0) && (((*gamer.move).y + cont) < n) &&
		    		matriz[(*gamer.move).x - cont][(*gamer.move).y + cont] == matriz[(*gamer.move).x][(*gamer.move).y] && matriz[(*gamer.move).x - cont][(*gamer.move).y + cont] != '-'){
		    		cont_ds++;
		    }
		    else{
		    	break;
		    }
		}
		}

		if ((*gamer.move).x != n-1){
		    for(cont = 1; cont < 5; cont++){//Para baixo
		    	if( (((*gamer.move).x + cont) >= 0) && (((*gamer.move).x + cont) < n) &&
		    		(((*gamer.move).y - cont) >= 0) && (((*gamer.move).y - cont) < n) &&
		    		matriz[(*gamer.move).x + cont][(*gamer.move).y - cont] == matriz[(*gamer.move).x][(*gamer.move).y] && matriz[(*gamer.move).x + cont][(*gamer.move).y - cont] != '-') {

		    		cont_ds++;
		    }
		    else{
		    	break;
		    }
		}

		}

		if(cont_ds >= 4){
			return 1;
		}


		return 0;
		}








		//funcao para capturar peça
		int captura_peca(int n, char **matriz, jogador gamer){


			//coluna para cima
			if((*gamer.move).x >= 3){
				if (matriz[(*gamer.move).x][(*gamer.move).y] == matriz[(*gamer.move).x - 3][(*gamer.move).y]){


					if ((matriz[(*gamer.move).x - 1][(*gamer.move).y] != matriz[(*gamer.move).x][(*gamer.move).y] && matriz[(*gamer.move).x - 1][(*gamer.move).y] != '-') &&
						(matriz[(*gamer.move).x - 2][(*gamer.move).y] != matriz[(*gamer.move).x][(*gamer.move).y] && matriz[(*gamer.move).x - 2][(*gamer.move).y] != '-')){

						matriz[(*gamer.move).x - 1][(*gamer.move).y] = '-';
					matriz[(*gamer.move).x - 2][(*gamer.move).y] = '-';
					return 1;
				}

			}
		}



		  //coluna para baixo
		if((*gamer.move).x <= n - 4){
			if (matriz[(*gamer.move).x][(*gamer.move).y] == matriz[(*gamer.move).x + 3][(*gamer.move).y]){


				if ((matriz[(*gamer.move).x + 1][(*gamer.move).y] != matriz[(*gamer.move).x][(*gamer.move).y] && matriz[(*gamer.move).x + 1][(*gamer.move).y] != '-') &&
					(matriz[(*gamer.move).x + 2][(*gamer.move).y] != matriz[(*gamer.move).x][(*gamer.move).y] && matriz[(*gamer.move).x + 2][(*gamer.move).y] != '-')){

					matriz[(*gamer.move).x + 1][(*gamer.move).y] = '-';
				matriz[(*gamer.move).x + 2][(*gamer.move).y] = '-';
				return 1;
			}

		}
		}


		  //linha para direita
		if((*gamer.move).y <= n - 4 && (*gamer.move).y >= 0){
			if (matriz[(*gamer.move).x][(*gamer.move).y] == matriz[(*gamer.move).x][(*gamer.move).y + 3]){


				if ((matriz[(*gamer.move).x][(*gamer.move).y + 1] != matriz[(*gamer.move).x][(*gamer.move).y] && matriz[(*gamer.move).x][(*gamer.move).y + 1] != '-') &&
					(matriz[(*gamer.move).x][(*gamer.move).y + 2] != matriz[(*gamer.move).x][(*gamer.move).y] && matriz[(*gamer.move).x][(*gamer.move).y + 2] != '-')){

					matriz[(*gamer.move).x][(*gamer.move).y + 1] = '-';
				matriz[(*gamer.move).x][(*gamer.move).y + 2] = '-';
				return 1;
			}

		}
		}



		  //linha para esquerda
		if((*gamer.move).y >= 3 && (*gamer.move).y < n){
			if (matriz[(*gamer.move).x][(*gamer.move).y] == matriz[(*gamer.move).x][(*gamer.move).y - 3]){


				if ((matriz[(*gamer.move).x][(*gamer.move).y - 1] != matriz[(*gamer.move).x][(*gamer.move).y] && matriz[(*gamer.move).x][(*gamer.move).y - 1] != '-') &&
					(matriz[(*gamer.move).x][(*gamer.move).y - 2] != matriz[(*gamer.move).x][(*gamer.move).y] && matriz[(*gamer.move).x][(*gamer.move).y - 2] != '-')){

					matriz[(*gamer.move).x][(*gamer.move).y - 1] = '-';
				matriz[(*gamer.move).x][(*gamer.move).y - 2] = '-';
				return 1;
			}
		} 
		}


		  //diagonal principal para cima
		if(((*gamer.move).x >= 3) && ((*gamer.move).y >= 3)){
			if (matriz[(*gamer.move).x][(*gamer.move).y] == matriz[(*gamer.move).x - 3][(*gamer.move).y - 3]){


				if ((matriz[(*gamer.move).x - 1][(*gamer.move).y - 1] != matriz[(*gamer.move).x][(*gamer.move).y] && matriz[(*gamer.move).x - 1][(*gamer.move).y - 1] != '-') &&
					(matriz[(*gamer.move).x - 2][(*gamer.move).y - 2] != matriz[(*gamer.move).x][(*gamer.move).y] && matriz[(*gamer.move).x - 2][(*gamer.move).y - 2] != '-')){

					matriz[(*gamer.move).x - 1][(*gamer.move).y - 1] = '-';
				matriz[(*gamer.move).x - 2][(*gamer.move).y - 2] = '-';
				return 1;
			}
		}
		}



		  //diagonal principal para baixo
		if(((*gamer.move).x <= n - 4) && ((*gamer.move).y <= n - 4)){
			if (matriz[(*gamer.move).x][(*gamer.move).y] == matriz[(*gamer.move).x + 3][(*gamer.move).y + 3]){


				if ((matriz[(*gamer.move).x + 1][(*gamer.move).y + 1] != matriz[(*gamer.move).x][(*gamer.move).y] && matriz[(*gamer.move).x + 1][(*gamer.move).y + 1] != '-') &&
					(matriz[(*gamer.move).x + 2][(*gamer.move).y + 2] != matriz[(*gamer.move).x][(*gamer.move).y] && matriz[(*gamer.move).x + 2][(*gamer.move).y + 2] != '-')){

					matriz[(*gamer.move).x + 1][(*gamer.move).y + 1] = '-';
				matriz[(*gamer.move).x + 2][(*gamer.move).y + 2] = '-';
				return 1;
			}
		}
		}



		  //diagonal secundaria para baixo
		if(((*gamer.move).x <= n - 4) && ((*gamer.move).y >= 3)){
			if (matriz[(*gamer.move).x][(*gamer.move).y] == matriz[(*gamer.move).x + 3][(*gamer.move).y - 3]){


				if ((matriz[(*gamer.move).x + 1][(*gamer.move).y - 1] != matriz[(*gamer.move).x][(*gamer.move).y] && matriz[(*gamer.move).x + 1][(*gamer.move).y - 1] != '-') &&
					(matriz[(*gamer.move).x + 2][(*gamer.move).y - 2] != matriz[(*gamer.move).x][(*gamer.move).y] && matriz[(*gamer.move).x + 2][(*gamer.move).y - 2] != '-')){

					matriz[(*gamer.move).x + 1][(*gamer.move).y - 1] = '-';
				matriz[(*gamer.move).x + 2][(*gamer.move).y - 2] = '-';
				return 1;
			}
		}

		}



		  //diagonal secundaria para cima
		if(((*gamer.move).x >= 3) && ((*gamer.move).y <= n - 4)){
			if (matriz[(*gamer.move).x][(*gamer.move).y] == matriz[(*gamer.move).x - 3][(*gamer.move).y + 3]){


				if ((matriz[(*gamer.move).x - 1][(*gamer.move).y + 1] != matriz[(*gamer.move).x][(*gamer.move).y] && matriz[(*gamer.move).x - 1][(*gamer.move).y + 1] != '-') &&
					(matriz[(*gamer.move).x - 2][(*gamer.move).y + 2] != matriz[(*gamer.move).x][(*gamer.move).y] && matriz[(*gamer.move).x - 2][(*gamer.move).y + 2] != '-')){

					matriz[(*gamer.move).x - 1][(*gamer.move).y + 1] = '-';
				matriz[(*gamer.move).x - 2][(*gamer.move).y + 2] = '-';
				return 1;
			}
		}
		}

		  //jogadas "suicidas"

		  /////analisando a linha na direção direita se jogador inseriu uma peça do lado de outra sua e entre duas adversárias 
		if((*gamer.move).y >= 1 && (*gamer.move).y <= n-3){
			if((matriz[(*gamer.move).x][(*gamer.move).y] == matriz[(*gamer.move).x][(*gamer.move).y+1]) && matriz[(*gamer.move).x][(*gamer.move).y+1] != '-') {
				if((matriz[(*gamer.move).x][(*gamer.move).y-1] == matriz[(*gamer.move).x][(*gamer.move).y+2]) && (matriz[(*gamer.move).x][(*gamer.move).y-1] != '-')){
					if((matriz[(*gamer.move).x][(*gamer.move).y-1] != matriz[(*gamer.move).x][(*gamer.move).y])){
						matriz[(*gamer.move).x][(*gamer.move).y] = '-';
						matriz[(*gamer.move).x][(*gamer.move).y+1] = '-';
						return 2;
					}
				}	
			}
		}
		  /////analisando a linha na direção esquerda se jogador inseriu uma peça do lado de outra sua e entre duas adversárias 
		if((*gamer.move).y>=2 && (*gamer.move).y<= n-2){
			if((matriz[(*gamer.move).x][(*gamer.move).y]== matriz[(*gamer.move).x][(*gamer.move).y-1]) && (matriz[(*gamer.move).x][(*gamer.move).y-1] != '-')){
				if((matriz[(*gamer.move).x][(*gamer.move).y-2] == matriz[(*gamer.move).x][(*gamer.move).y+1]) && (matriz[(*gamer.move).x][(*gamer.move).y-2] != '-')){
					if(matriz[(*gamer.move).x][(*gamer.move).y] != matriz[(*gamer.move).x][(*gamer.move).y-2]){
						matriz[(*gamer.move).x][(*gamer.move).y] = '-';
						matriz[(*gamer.move).x][(*gamer.move).y-1] = '-';
						return 2;
					}
				} 
			}
		}
		  /////verificando a coluna na parte de cima
		if((*gamer.move).x>=1 && (*gamer.move).x <= n-3){
			if((matriz[(*gamer.move).x][(*gamer.move).y] == matriz[(*gamer.move).x+1][(*gamer.move).y]) && (matriz[(*gamer.move).x+1][(*gamer.move).y] != '-')){
				if((matriz[(*gamer.move).x-1][(*gamer.move).y] == matriz[(*gamer.move).x+2][(*gamer.move).y]) && (matriz[(*gamer.move).x-1][(*gamer.move).y] != '-') && matriz[(*gamer.move).x-1][(*gamer.move).y] != matriz[(*gamer.move).x][(*gamer.move).y]){
					matriz[(*gamer.move).x][(*gamer.move).y] = '-';
					matriz[(*gamer.move).x+1][(*gamer.move).y] = '-';
					return 2;
				}
			}
		}
		    /////verificando a coluna na parte de baixo
		if((*gamer.move).x>=2 && (*gamer.move).x <= n-2){
			if((matriz[(*gamer.move).x][(*gamer.move).y] == matriz[(*gamer.move).x-1][(*gamer.move).y]) && (matriz[(*gamer.move).x-1][(*gamer.move).y] != '-')){
				if((matriz[(*gamer.move).x+1][(*gamer.move).y] == matriz[(*gamer.move).x-2][(*gamer.move).y]) && (matriz[(*gamer.move).x+1][(*gamer.move).y] != '-') && matriz[(*gamer.move).x+1][(*gamer.move).y] != matriz[(*gamer.move).x][(*gamer.move).y]){
					matriz[(*gamer.move).x][(*gamer.move).y] = '-';
					matriz[(*gamer.move).x-1][(*gamer.move).y] = '-';
					return 2;
				}
			}
		}

		  //verificando a diagonal principal na parte de cima
		if((*gamer.move).x >=1 && (*gamer.move).x <= n-3){
			if((*gamer.move).y >= 1 && (*gamer.move).y <= n-3){
				if(matriz[(*gamer.move).x][(*gamer.move).y] == matriz[(*gamer.move).x+1][(*gamer.move).y+1] && matriz[(*gamer.move).x][(*gamer.move).y] != '-'){
					if(matriz[(*gamer.move).x-1][(*gamer.move).y-1] == matriz[(*gamer.move).x+2][(*gamer.move).y+2] && matriz[(*gamer.move).x-1][(*gamer.move).y-1] != '-'){
						if(matriz[(*gamer.move).x][(*gamer.move).y] != matriz[(*gamer.move).x-1][(*gamer.move).y-1]){
							matriz[(*gamer.move).x][(*gamer.move).y] = '-';
							matriz[(*gamer.move).x+1][(*gamer.move).y+1] = '-';
							return 2;
						}
					} 
				}
			}
		}

		  //verificando a diagonal principal na parte de baixo
		if((*gamer.move).x>=2 && (*gamer.move).x <= n-2){
			if((*gamer.move).y >= 2 && (*gamer.move).y <= n-2){
				if(matriz[(*gamer.move).x][(*gamer.move).y] == matriz[(*gamer.move).x-1][(*gamer.move).y-1] && matriz[(*gamer.move).x][(*gamer.move).y] != '-'){
					if(matriz[(*gamer.move).x+1][(*gamer.move).y+1] == matriz[(*gamer.move).x-2][(*gamer.move).y-2] && matriz[(*gamer.move).x+1][(*gamer.move).y+1] != '-'){
						if(matriz[(*gamer.move).x][(*gamer.move).y] != matriz[(*gamer.move).x+1][(*gamer.move).y+1]){
							matriz[(*gamer.move).x][(*gamer.move).y] = '-';
							matriz[(*gamer.move).x-1][(*gamer.move).y-1] = '-';
							return 2;
						}
					}

				}
			}
		}
		  	//diagonal secundaria pra baixo
		if((*gamer.move).x >= 1 && (*gamer.move).x <= n-3){
			if((*gamer.move).y >= 1 && (*gamer.move).y <= n-3){
				if(matriz[(*gamer.move).x][(*gamer.move).y] == matriz[(*gamer.move).x+1][(*gamer.move).y-1] && matriz[(*gamer.move).x][(*gamer.move).y] != '-'){
					if(matriz[(*gamer.move).x-1][(*gamer.move).y+1] == matriz[(*gamer.move).x+2][(*gamer.move).y-2] && matriz[(*gamer.move).x-1][(*gamer.move).y+1] != '-'){
						if(matriz[(*gamer.move).x][(*gamer.move).y] != matriz[(*gamer.move).x-1][(*gamer.move).y+1]){
							matriz[(*gamer.move).x][(*gamer.move).y] = '-';
							matriz[(*gamer.move).x+1][(*gamer.move).y-1] = '-';
							return 2;
						}
					}
				}
			}
		}
		  	//diagonal secundaria pra cima
		if((*gamer.move).x >= 2 && (*gamer.move).x<= n-2){
			if((*gamer.move).y >= 2 && (*gamer.move).y <= n-2){
				if(matriz[(*gamer.move).x][(*gamer.move).y] == matriz[(*gamer.move).x-1][(*gamer.move).y+1] && matriz[(*gamer.move).x][(*gamer.move).y] != '-'){
					if(matriz[(*gamer.move).x+1][(*gamer.move).y-1] == matriz[(*gamer.move).x-2][(*gamer.move).y+2] && matriz[(*gamer.move).x+1][(*gamer.move).y-1] != '-'){
						if(matriz[(*gamer.move).x][(*gamer.move).y] != matriz[(*gamer.move).x+1][(*gamer.move).y-1]){
							matriz[(*gamer.move).x][(*gamer.move).y] = '-';
							matriz[(*gamer.move).x-1][(*gamer.move).y+1] = '-';
							return 2;
						}
					}
				}
			}
		}
		return 0;
		}








		int deseja_continuar(char opc_continue[]){
			char decide[3];
			int opcao,i;

			printf("\nDeseja continuar? (sim | nao) \n");
			scanf("%s", decide);
			for(i = 0; i < 3; i++){
				decide[i] = tolower(decide[i]);
			}

			opcao = strcmp(opc_continue, decide);

			return opcao;
			 // O jogador escolhe continuar se return for 0
			 // O jogador escolhe não continuar se return for 1

		}









		//alterna jogadas e printa o goban
		void alternar_jogadas(int n, char **matriz, char *p, jogador j1, jogador j2){
			int i, captura;



			for(i = 0; i < (n*n/2)+1; i++){
				if (j1.cor == 1){//se j1 eh preto
					if (i >= 0 && i < (n*n/2)){

						printf("Vez de %s (B)\n", j1.nome);
						atualiza_jogo(matriz, n, j1);
						captura = captura_peca(n, matriz, j1);
						if(captura==2){
							i = i - 2;
						}
						if(captura == 1){
							i = i-2;
							j1.captura = j1.captura + captura;
						}	
						//system("clear");
						chama_tela(n, matriz, p);
						j1.comp = verifique_vitoria(n, matriz, j1);				
						printf("Capturas:\t%s %d X %d %s\n",j1.nome, j1.captura,j2.captura, j2.nome);




						
						printf("Vez de %s (W)\n", j2.nome);
						atualiza_jogo(matriz, n, j2);
						captura = captura_peca(n, matriz, j2);
						if(captura==2){
							i = i - 2;
						}
						if(captura == 1){
							i = i-2;
							j2.captura = j2.captura + captura;
						}	
						//system("clear");
						chama_tela(n, matriz, p);
						j2.comp = verifique_vitoria(n, matriz, j2);
						printf("Capturas:\t%s %d X %d %s\n",j1.nome, j1.captura,j2.captura, j2.nome);


						

					}else if (i == (n*n/2)){
						
						printf("Vez de %s (B)\n", j1.nome);
						atualiza_jogo(matriz, n, j1);
						captura = captura_peca(n, matriz, j1);
						//system("clear");
						chama_tela(n, matriz, p);
						j1.comp = verifique_vitoria(n, matriz, j1);
						if(captura == 1){
							j1.captura= j1.captura + captura;
							printf("Capturas:\t%s %d X %d %s\n",j1.nome, j1.captura,j2.captura, j2.nome);

							
							printf("Vez de %s (W)\n", j2.nome);
							atualiza_jogo(matriz, n, j2);
							captura = captura_peca(n, matriz, j2);
							if(captura == 2){
								i = i-2;
							}
							if(captura == 1){
								i = i-2;
								j2.captura = j2.captura + captura;
							}
							
							//system("clear");
							chama_tela(n, matriz, p);
							j2.comp = verifique_vitoria(n, matriz, j2);
							printf("Capturas:\t%s %d X %d %s\n",j1.nome, j1.captura,j2.captura, j2.nome);

							printf("Vez de %s (B)\n", j1.nome);
							atualiza_jogo(matriz, n, j1);
							captura = captura_peca(n, matriz, j1);
							if(captura == 2){
								i = i-2;
							}
							if(captura == 1){
								i = i-2;
								j1.captura = j1.captura + captura;
							}
							//system("clear");
							chama_tela(n, matriz, p);
							j1.comp = verifique_vitoria(n, matriz, j1);
							printf("Capturas:\t%s %d X %d %s\n",j1.nome, j1.captura,j2.captura, j2.nome);
						}


					}
					

					if((j1.comp == j2.comp) && (i == (n*n/2))){
						printf("Empate\n");
						break;
					}

					if((j1.comp == 1) && (j2.comp== 1)){
						printf("Empate\n");
						break;
					}

					if(j1.comp == 1 && j2.comp == 0){				
						*(j1).vitoria = *(j1).vitoria + 1;				
						printf("Vitória por alinhamento de peças.\n");
						printf("Vitoria do jogador %s(B).\n", j1.nome);
						printf("Placar:\n\t%s %d X %d %s\n",j1.nome, *j1.vitoria, *j2.vitoria, j2.nome);
						break;
					}
					if(j1.comp == 0 && j2.comp == 1){
						*(j2).vitoria = *(j2).vitoria + 1;
						printf("Vitória por alinhamento de peças.\n");
						printf("Vitoria do jogador %s(B).\n", j2.nome);		
						printf("Placar:\n\t%s %d X %d %s\n",j1.nome, *j1.vitoria, *j2.vitoria, j2.nome);
						break;
					}

					if (j1.captura == 5){
						*(j1).vitoria = *(j1).vitoria + 1;
						printf("Vitória por captura.\n");
						printf("Vitoria do jogador %s(W).\n",j1.nome);
						printf("Placar:\n\t%s %d X %d %s\n", j1.nome, *j1.vitoria, *j2.vitoria, j2.nome);				
						break;
					}

					if (j2.captura == 5){
						*(j2).vitoria = *(j2).vitoria + 1;
						printf("Vitória por captura.\n");
						printf("Vitória do jogador %s(B).\n",j2.nome);				
						printf("Placar:\n\t%s %d X %d %s\n", j1.nome, *j1.vitoria, *j2.vitoria, j2.nome);
						break;
					}
				}
				else if (j2.cor == 1){//se j2 eh preto
					if (i >= 0 && i < (n*n/2)){

						printf("Vez de %s (B)\n", j2.nome);
						atualiza_jogo(matriz, n, j2);
						captura = captura_peca(n, matriz, j2);
						if(captura==2){
							i = i - 2;
						}
						if(captura == 1){
							i = i-2;
							j2.captura = j2.captura + captura;
						}	
						//system("clear");
						chama_tela(n, matriz, p);
						j2.comp = verifique_vitoria(n, matriz, j2);				
						printf("Capturas:\t%s %d X %d %s\n",j1.nome, j1.captura,j2.captura, j2.nome);
						



						printf("Vez de %s (W)\n", j1.nome);
						atualiza_jogo(matriz, n, j1);
						captura = captura_peca(n, matriz, j1);
						if(captura==2){
							i = i - 2;
						}
						if(captura == 1){
							i = i-2;
							j1.captura = j1.captura + captura;
						}	
						////system("clear");
						chama_tela(n, matriz, p);
						j1.comp = verifique_vitoria(n, matriz, j1);				
						printf("Capturas:\t%s %d X %d %s\n",j1.nome, j1.captura,j2.captura, j2.nome);
						

					}else if (i == (n*n/2)){
						printf("Vez de %s (B)\n", j2.nome);
						atualiza_jogo(matriz, n, j2);
						captura = captura_peca(n, matriz, j2);
						////system("clear");
						chama_tela(n, matriz, p);
						j2.comp = verifique_vitoria(n, matriz, j2);
						if(captura == 1){
							j2.captura = j2.captura + captura;
							printf("Capturas:\t%s %d X %d %s\n",j1.nome, j1.captura,j2.captura, j2.nome);
							
							printf("Vez de %s (W)\n", j1.nome);
							atualiza_jogo(matriz, n, j1);
							captura = captura_peca(n, matriz, j1);
							if(captura == 2){
								i = i-2;
							}
							if(captura == 1){
								i = i-2;
								j1.captura = j1.captura + captura;
							}
							////system("clear");
							chama_tela(n, matriz, p);
							j1.comp = verifique_vitoria(n, matriz, j1);
							printf("Capturas:\t%s %d X %d %s\n",j1.nome, j1.captura,j2.captura, j2.nome);


							printf("Vez de %s (B)\n", j2.nome);
							atualiza_jogo(matriz, n, j2);
							captura = captura_peca(n, matriz, j2);
							if(captura == 2){
								i=i-2;
							}
							if(captura == 1){
								i = i-2;
								j2.captura = j2.captura + captura;
							}
							////system("clear");
							chama_tela(n, matriz, p);
							j2.comp = verifique_vitoria(n, matriz, j2);
							printf("Capturas:\t%s %d X %d %s\n",j1.nome, j1.captura,j2.captura, j2.nome);
						}
						
					}
					

					if((j1.comp == j2.comp) && (i == (n*n/2))){
						printf("Empate\n");
						break;
					}

					if((j1.comp == 1) && (j2.comp == 1)){
						printf("Empate\n");
						break;
					}

					if(j1.comp == 1 && j2.comp == 0){
						*(j1).vitoria = *(j1).vitoria + 1;
						printf("Vitória por alinhamento de peças.\n");
						printf("Vitoria do jogador %s(W).\n", j1.nome);		
						printf("Placar:\n\t%s %d X %d %s\n",j1.nome, *j1.vitoria, *j2.vitoria, j2.nome);		
						break;
					}
					if(j1.comp == 0 && j2.comp == 1){
						*(j2).vitoria = *(j2).vitoria + 1;
						printf("Vitória por alinhamento de peças.\n");
						printf("Vitoria do jogador %s(B).\n", j2.nome);		
						printf("Placar:\n\t%s %d X %d %s\n",j1.nome, *j1.vitoria, *j2.vitoria, j2.nome);		
						break;
					}

					if (j1.captura == 5){
						*(j1).vitoria = *(j1).vitoria + 1;
						printf("Vitória por captura.\n");
						printf("Vitoria do jogador %s(W).\n",j1.nome);
						printf("Placar:\n\t%s %d X %d %s\n", j1.nome, *j1.vitoria, *j2.vitoria, j2.nome);				
						break;
					}

					if (j2.captura == 5){
						*(j2).vitoria = *(j2).vitoria + 1;
						printf("Vitória por captura.\n");
						printf("Vitória do jogador %s(B).\n",j2.nome);				
						printf("Placar:\n\t%s %d X %d %s\n", j1.nome, *j1.vitoria, *j2.vitoria, j2.nome);
						break;
					}
				}
			}

		}