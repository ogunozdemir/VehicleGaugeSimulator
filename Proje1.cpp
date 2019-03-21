#include <allegro.h>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdlib>

void baslat();
void bitir();

using namespace std;

class Araba{

public:
	
	FILE *TOPLAM;
	bool ElFreni=0, KisaFar=0, UzunFar=0, EmniyetKemeri=0, OnSis=0, ArkaSis=0, ParkLamb=0;
	float radyan1, radyan2, radyan3, radyan4, h1, h2, m1, m2, b1, b2, s1, s2;
	float aci1,aci2,aci3=320,aci4;
	float km,toplamkm;
	int vites,korna=100,motor=0,benzin=0;
	bool solsinyal=false, sagsinyal=false, dortsinyal=false;
	
	BITMAP *AraKatman=create_bitmap(800,480);
 	
 	BITMAP *GostergePaneli1=load_bitmap("panels/gostergepaneli1.bmp",NULL);
 	BITMAP *GostergePaneli2=load_bitmap("panels/gostergepaneli2.bmp",NULL);
 	BITMAP *HizGostergesi=load_bitmap("panels/hizgostergesi.bmp",NULL);
 	BITMAP *MotorGostergesi=load_bitmap("panels/motorgostergesi.bmp",NULL);
 	BITMAP *BenzinGostergesi=load_bitmap("panels/benzingostergesi.bmp",NULL);
 	BITMAP *SicaklikGostergesi=load_bitmap("panels/sicaklikgostergesi.bmp",NULL);
 	BITMAP *TemizVites=load_bitmap("panels/temizvites.bmp",NULL);
 	BITMAP *TemizKm=load_bitmap("panels/temizkm.bmp",NULL);
 	BITMAP *TemizToplamKm=load_bitmap("panels/temiztoplamkm.bmp",NULL);
 	
 	BITMAP *StartButton=load_bitmap("buttons/startbutton.bmp",NULL);
 	BITMAP *StopButton=load_bitmap("buttons/stopbutton.bmp",NULL);
 	BITMAP *RadyoButton=load_bitmap("buttons/radyobutton.bmp",NULL);
 	BITMAP *RadyoButtonSil=load_bitmap("buttons/radyobuttonsil.bmp",NULL);
 	
	BITMAP *SagSinyal1=load_bitmap("icons soft/sagsinyal1.bmp",NULL);
	BITMAP *SagSinyal2=load_bitmap("icons bright/sagsinyal2.bmp",NULL);
	BITMAP *SolSinyal1=load_bitmap("icons soft/solsinyal1.bmp",NULL);
	BITMAP *SolSinyal2=load_bitmap("icons bright/solsinyal2.bmp",NULL);
	
	BITMAP *KisaFar1=load_bitmap("icons soft/kisafar1.bmp",NULL);
	BITMAP *KisaFar2=load_bitmap("icons bright/kisafar2.bmp",NULL);
	BITMAP *UzunFar1=load_bitmap("icons soft/uzunfar1.bmp",NULL);
	BITMAP *UzunFar2=load_bitmap("icons bright/uzunfar2.bmp",NULL);
	BITMAP *ParkLamb1=load_bitmap("icons soft/parklamb1.bmp",NULL);
	BITMAP *ParkLamb2=load_bitmap("icons bright/parklamb2.bmp",NULL);
	BITMAP *ArkaSis1=load_bitmap("icons soft/arkasis1.bmp",NULL);
	BITMAP *ArkaSis2=load_bitmap("icons bright/arkasis2.bmp",NULL);
	BITMAP *OnSis1=load_bitmap("icons soft/onsis1.bmp",NULL);
	BITMAP *OnSis2=load_bitmap("icons bright/onsis2.bmp",NULL);
	
	BITMAP *Sicaklik1=load_bitmap("icons bright/sicaklik1.bmp",NULL);
	BITMAP *Sicaklik2=load_bitmap("icons bright/sicaklik2.bmp",NULL);
	BITMAP *Benzin1=load_bitmap("icons bright/benzin1.bmp",NULL);
	BITMAP *Benzin2=load_bitmap("icons bright/benzin2.bmp",NULL);
 	
	BITMAP *Aku1=load_bitmap("icons soft/aku1.bmp",NULL);
	BITMAP *Aku2=load_bitmap("icons bright/aku2.bmp",NULL);
	BITMAP *Motor1=load_bitmap("icons soft/motor1.bmp",NULL);
	BITMAP *Motor2=load_bitmap("icons bright/motor2.bmp",NULL);
	BITMAP *Yag1=load_bitmap("icons soft/yag1.bmp",NULL);
	BITMAP *Yag2=load_bitmap("icons bright/yag2.bmp",NULL);
	
	BITMAP *ElFreni1=load_bitmap("icons soft/elfreni1.bmp",NULL);
	BITMAP *ElFreni2=load_bitmap("icons bright/elfreni2.bmp",NULL);
	
	BITMAP *Radyo1=load_bitmap("icons soft/radyo1.bmp",NULL);
	BITMAP *Radyo2=load_bitmap("icons bright/radyo2.bmp",NULL);
	
	BITMAP *Korna1=load_bitmap("icons soft/korna1.bmp",NULL);
	BITMAP *Korna2=load_bitmap("icons bright/korna2.bmp",NULL);
	
	BITMAP *EmniyetKemeri1=load_bitmap("icons soft/emniyetkemeri1.bmp",NULL);
	BITMAP *EmniyetKemeri2=load_bitmap("icons bright/emniyetkemeri2.bmp",NULL);
	
	BITMAP *HavaYastigi1=load_bitmap("icons soft/havayastigi1.bmp",NULL);
	BITMAP *HavaYastigi2=load_bitmap("icons bright/havayastigi2.bmp",NULL);
	
	BITMAP *Kontak1=load_bitmap("icons soft/kontak1.bmp",NULL);
	BITMAP *Kontak2=load_bitmap("icons bright/kontak2.bmp",NULL);
	
	SAMPLE *MarsSesi=load_sample("sounds/MarsSesi.wav");
	SAMPLE *MotorSesi=load_sample("sounds/MotorSesi.wav");
 	SAMPLE *EmniyetSesi=load_sample("sounds/EmniyetSesi.wav");
 	SAMPLE *Dortlu=load_sample("sounds/Dortlu.wav");
 	SAMPLE *Sinyal=load_sample("sounds/Sinyal.wav");
 	SAMPLE *KornaSesi=load_sample("sounds/KornaSesi.wav");
 	SAMPLE *BipSesi=load_sample("sounds/BipSesi.wav");
 	
 	SAMPLE *AmanAman=load_sample("tracks/AmanAman.wav");
 	SAMPLE *ByeByeLove=load_sample("tracks/ByeByeLove.wav");
 	SAMPLE *Nilufer=load_sample("tracks/Nilufer.wav");
 	SAMPLE *Albatraoz=load_sample("tracks/Albatraoz.wav");
	
	void arackapali()
	{
		km=0;
 		vites=1;
 		aci1=160;
 		aci2=160;
 		aci4=220;
 		
 		clear_to_color(AraKatman, makecol(0,0,0));
 		blit(GostergePaneli1,AraKatman,0,0,0,0,800,320);
 		blit(StartButton,AraKatman,0,0,250,350,100,100);
 		blit(StopButton,AraKatman,0,0,450,350,100,100);
 		
 		radyan1=float(aci1*3.14/180);
 		h1=cos(radyan1)*90+623;
    	h2=sin(radyan1)*90+185;
		line(AraKatman,h1,h2,623,185,makecol(255,0,0));
		
		radyan2=float(aci2*3.14/180);
	 	m1=cos(radyan2)*90+182;
 	 	m2=sin(radyan2)*90+185;
		line(AraKatman,m1,m2,182,185,makecol(255,0,0));
		
		radyan3=float(aci3*3.14/180);
	    b1=cos(radyan3)*27+456;
		b2=sin(radyan3)*27+72;
		line(AraKatman,b1,b2,456,72,makecol(255,0,0));
		
		radyan4=float(aci4*3.14/180);
	    s1=cos(radyan4)*27+348;
	    s2=sin(radyan4)*27+72;
	    line(AraKatman,s1,s2,348,72,makecol(255,0,0));
		
 		blit(AraKatman,screen,0,0,0,0,800,480);
 		
 		stop_sample(MarsSesi);
		stop_sample(MotorSesi);
		stop_sample(EmniyetSesi);
		stop_sample(Nilufer);
		stop_sample(AmanAman);
		stop_sample(ByeByeLove);
		stop_sample(Albatraoz);
	}
	
	void aracacik()
	{
 	        TOPLAM=fopen("ToplamKm.txt","r");
			fscanf(TOPLAM,"%f",&toplamkm);
			fclose(TOPLAM);
			
 			play_sample(MarsSesi,40/*ses seviyesi*/,128/*sað ya da sol hoparlör ayarý*/,1000/*ses hýzý ayarý*/,0);
		    play_sample(MotorSesi,30/*ses seviyesi*/,128/*sað ya da sol hoparlör ayarý*/,1000/*ses hýzý ayarý*/,1);
 			
 			clear_bitmap(AraKatman);
			blit(GostergePaneli2,AraKatman,0,0,0,0,800,320);
 			blit(StartButton,AraKatman,0,0,250,350,100,100);
 			blit(StopButton,AraKatman,0,0,450,350,100,100);
 			textprintf_ex(AraKatman,font,362,262, makecol(255,255,255),-1,"%d",vites);
 			
 			radyan1=float(aci1*3.14/180);
 			h1=cos(radyan1)*90+623;
    		h2=sin(radyan1)*90+185;
			line(AraKatman,h1,h2,623,185,makecol(255,0,0));
			
			radyan2=float(aci2*3.14/180);
	 		m1=cos(radyan2)*90+182;
 	 		m2=sin(radyan2)*90+185;
			line(AraKatman,m1,m2,182,185,makecol(255,0,0));
			
			radyan3=float(aci3*3.14/180);
	    	b1=cos(radyan3)*27+456;
			b2=sin(radyan3)*27+72;
			line(AraKatman,b1,b2,456,72,makecol(255,0,0));
			
			radyan4=float(aci4*3.14/180);
	    	s1=cos(radyan4)*27+348;
	    	s2=sin(radyan4)*27+72;
	    	line(AraKatman,s1,s2,348,72,makecol(255,0,0));
	    	
	    	textprintf_ex(AraKatman,font,405,230, makecol(255,255,255),-1,"%.0fkm",toplamkm);
	        textprintf_ex(AraKatman,font,415,260, makecol(255,255,255),-1,"%.0fkm",km);
		
 			blit(AraKatman,screen,0,0,0,0,800,480);
 			rest(2000);
 			
 			blit(Radyo1,AraKatman,0,0,111,246,18,21);
 			blit(SolSinyal1,AraKatman,0,0,265,36,31,26);
 			blit(SagSinyal1,AraKatman,0,0,510,34,31,26);
 			blit(UzunFar1,AraKatman,0,0,529,250,27,19);
			blit(KisaFar1,AraKatman,0,0,564,249,25,20);
 			blit(Kontak1,AraKatman,0,0,534,226,30,14);
 			blit(Yag1,AraKatman,0,0,214,257,28,12);
 			blit(HavaYastigi1,AraKatman,0,0,176,248,24,22);
 			blit(Aku1,AraKatman,0,0,235,224,25,19);
 			blit(Motor1,AraKatman,0,0,249,251,26,18);
 			blit(ElFreni1,AraKatman,0,0,150,226,19,17);
 			blit(ArkaSis1,AraKatman,0,0,651,248,25,20);
 			blit(OnSis1,AraKatman,0,0,682,248,25,20);
 			blit(Korna1,AraKatman,0,0,143,249,24,19);
 			
 			radyan1=float(aci1*3.14/180);
 			h1=cos(radyan1)*90+623;
    		h2=sin(radyan1)*90+185;
 			line(AraKatman,h1,h2,623,185,makecol(255,0,0));
 			
 			radyan2=float(aci2*3.14/180);
	 		m1=cos(radyan2)*90+182;
 	 		m2=sin(radyan2)*90+185;
			line(AraKatman,m1,m2,182,185,makecol(255,0,0));
			
			radyan3=float(aci3*3.14/180);
	    	b1=cos(radyan3)*27+456;
			b2=sin(radyan3)*27+72;
			line(AraKatman,b1,b2,456,72,makecol(255,0,0));
			
			radyan4=float(aci4*3.14/180);
	    	s1=cos(radyan4)*27+348;
	      	s2=sin(radyan4)*27+72;
	    	line(AraKatman,s1,s2,348,72,makecol(255,0,0));
	    	
	    	textprintf_ex(AraKatman,font,405,230, makecol(255,255,255),-1,"%.0fkm",toplamkm);
	        textprintf_ex(AraKatman,font,415,260, makecol(255,255,255),-1,"%.0fkm",km);
 			
 			play_sample(EmniyetSesi,255/*ses seviyesi*/,128/*sað ya da sol hoparlör ayarý*/,1000/*ses hýzý ayarý*/,1);
 			
 			blit(AraKatman,screen,0,0,0,0,800,480);			//SONRADAN EKLEDÝM.	
	}
	
	void hareket()
	{
		if(key[KEY_UP])
 				{
 					if(ElFreni==0)
 					{
					 	if(aci4>319)
	        			{
	        				motor=1;
	        				play_sample(BipSesi,255/*ses seviyesi*/,128/*sað ya da sol hoparlör ayarý*/,1000/*ses hýzý ayarý*/,0);
	        			}
						
						if(motor==1)
						{
							blit(Sicaklik1,AraKatman,0,0,339,95,22,19);
							blit(Motor2,AraKatman,0,0,249,251,26,18);
	        				blit(AraKatman,screen,0,0,0,0,800,480);
	        				rest(90);
							goto motorarizasi;
						}	
 					 	
 					 	if(aci3<221)
 					 	{
 					 		if(benzin==0)
 					 		play_sample(BipSesi,255/*ses seviyesi*/,128/*sað ya da sol hoparlör ayarý*/,1000/*ses hýzý ayarý*/,0);
 					 		benzin=1;
 					 		blit(Benzin1,AraKatman,0,0,446,95,22,19);
 					 		blit(AraKatman,screen,0,0,0,0,800,480);
 					 		rest(90);
 					 		goto benzinbitti;
 					 	}
		   		     
		   		     rest(30);
		   		     
	  	 			 if(aci1<380 && aci3>221 || aci2<380 && aci3>221)
    	 			 {
    	 			 	
		 			 radyan1=float(aci1*3.14/180);
	        		 h1=cos(radyan1)*90+623;
	    	    	 h2=sin(radyan1)*90+185;
	    	    	 
  	 					   if(aci2>320 && aci1<350)
  	 					   {
  	 					   	aci2=200;
  	 					   	if(vites<5)
  	 					   	vites++;
  	 					   }
	    	    
	    		     radyan2=float(aci2*3.14/180);
	    	    	 m1=cos(radyan2)*90+182;
	    	    	 m2=sin(radyan2)*90+185;
	    	    	 
	    	    	 radyan3=float(aci3*3.14/180);
	    	    	 b1=cos(radyan3)*27+456;
	    	    	 b2=sin(radyan3)*27+72;
	    	    	 
	    	    	 radyan4=float(aci4*3.14/180);
	    	    	 s1=cos(radyan4)*27+348;
	    	    	 s2=sin(radyan4)*27+72;
	    	
	    			 blit(HizGostergesi,AraKatman,0,0,514,62,218,164);
	        		 line(AraKatman,h1,h2,623,185,makecol(255,0,0));
	        		 
	        		 blit(MotorGostergesi,AraKatman,0,0,60,68,239,156);
	        		 line(AraKatman,m1,m2,182,185,makecol(255,0,0));
	        		 
	        		 blit(BenzinGostergesi,AraKatman,0,0,424,26,64,53);
	        		 line(AraKatman,b1,b2,456,72,makecol(255,0,0));
	        		 
	        		 blit(SicaklikGostergesi,AraKatman,0,0,314,30,72,50);
	        		 line(AraKatman,s1,s2,348,72,makecol(255,0,0));
	        		 
	        		 blit(TemizVites,AraKatman,0,0,355,258,20,16);
	        		 textprintf_ex(AraKatman,font,362,262, makecol(255,255,255),-1,"%d",vites);
	        		 
	        		 blit(AraKatman,screen,0,0,0,0,800,480);
	        		 
						   if(aci1<380)
	            	 	   aci1++;
	            
	            	 	   if(aci2<380)
	            	 	   aci2=aci2+3.2;	 
					 }
					 	radyan3=float(aci3*3.14/180);
	    				b1=cos(radyan3)*27+456;
	    				b2=sin(radyan3)*27+72;
	    				
	    				radyan4=float(aci4*3.14/180);
	    				s1=cos(radyan4)*27+348;
	    				s2=sin(radyan4)*27+72;
	    				
	    				TOPLAM=fopen("ToplamKm.txt","r");
						fscanf(TOPLAM,"%f",&toplamkm);
						fclose(TOPLAM);
	    				
	    				if(aci1>160 && aci1<=195)
	    				{
						km=km+0.005;
						toplamkm=toplamkm+0.005;
						}
					 	else if(aci1>195 && aci1<=230)
					 	{
						km=km+0.016;
						toplamkm=toplamkm+0.016;
						}
					 	else if(aci1>230 && aci1<=270)
					 	{
						km=km+0.026;
						toplamkm=toplamkm+0.026;
						}
					 	else if(aci1>270 && aci1<=305)
					 	{
						km=km+0.038;
						toplamkm=toplamkm+0.038;
						}
					 	else if(aci1>305 && aci1<=343)
					 	{
						km=km+0.05;
						toplamkm=toplamkm+0.05;
						}
					 	else if(aci1>343 && aci1<=380)
					 	{
					 	km=km+0.06;
						toplamkm=toplamkm+0.06;
					 	}
						
						TOPLAM=fopen("ToplamKm.txt","w+");
						fprintf(TOPLAM,"%.3f",toplamkm);
						fclose(TOPLAM);
						
						blit(BenzinGostergesi,AraKatman,0,0,424,26,64,53);
						line(AraKatman,b1,b2,456,72,makecol(255,0,0));
						
						blit(SicaklikGostergesi,AraKatman,0,0,314,30,72,50);
	        		 	line(AraKatman,s1,s2,348,72,makecol(255,0,0));
	        		 	
	        		 	blit(TemizToplamKm,AraKatman,0,0,389,220,66,20);
	        		 	textprintf_ex(AraKatman,font,405,230, makecol(255,255,255),-1,"%.0fkm",toplamkm);
	        		 	
	        		 	blit(TemizKm,AraKatman,0,0,414,248,40,27);
	        		 	textprintf_ex(AraKatman,font,415,260, makecol(255,255,255),-1,"%.0fkm",km);
	        		 	
	        			blit(AraKatman,screen,0,0,0,0,800,480);
	        
						if(aci3>220)
	        			aci3=aci3-0.1;
	        			
	        			if(aci4<272)
	        			aci4=aci4+0.4;
	        			if(aci4>271 && aci4<320)
	        			aci4=aci4+0.1;	
                    }
				 }
				 
				 if(key[KEY_DOWN] || ElFreni==1)
 				 {
				     rest(15);
				     
 					 if(aci1>160 || aci2>160 || aci4>220)
					 {
	       			 radyan1=float(aci1*3.14/180);
	        		 h1=cos(radyan1)*90+623;
	    	    	 h2=sin(radyan1)*90+185;
	    	    	 
	    	    	 	if(aci2<200 && aci1>161)
  	 					{
  	 						if(vites>1)
  	 						{
  	 							aci2=320;
  	 					   		vites--;
  	 						}	
  	 					}
	    	    	 
	    	    	 radyan2=float(aci2*3.14/180);
    	    		 m1=cos(radyan2)*90+182;
 	   				 m2=sin(radyan2)*90+185;
 	   				 
 	   				 radyan4=float(aci4*3.14/180);
	    			 s1=cos(radyan4)*27+348;
	    			 s2=sin(radyan4)*27+72;
	    			 
	    			 	TOPLAM=fopen("ToplamKm.txt","r");
						fscanf(TOPLAM,"%f",&toplamkm);
						fclose(TOPLAM);
	    				
	    				if(aci1>160 && aci1<=195)
	    				{
						km=km+0.005;
						toplamkm=toplamkm+0.005;
						}
					 	else if(aci1>195 && aci1<=230)
					 	{
						km=km+0.016;
						toplamkm=toplamkm+0.016;
						}
					 	else if(aci1>230 && aci1<=270)
					 	{
						km=km+0.026;
						toplamkm=toplamkm+0.026;
						}
					 	else if(aci1>270 && aci1<=305)
					 	{
						km=km+0.038;
						toplamkm=toplamkm+0.038;
						}
					 	else if(aci1>305 && aci1<=343)
					 	{
						km=km+0.05;
						toplamkm=toplamkm+0.05;
						}
					 	else if(aci1>343 && aci1<=380)
					 	{
					 	km=km+0.06;
						toplamkm=toplamkm+0.06;
					 	}
						
						TOPLAM=fopen("ToplamKm.txt","w+");
						fprintf(TOPLAM,"%.3f",toplamkm);
						fclose(TOPLAM);
	    		
	    			 blit(HizGostergesi,AraKatman,0,0,514,62,800,320);
	        		 line(AraKatman,h1,h2,623,185,makecol(255,0,0));
	        		 
	        		 blit(MotorGostergesi,AraKatman,0,0,60,68,239,156);
	        		 line(AraKatman,m1,m2,182,185,makecol(255,0,0));
	        		 
	        		 blit(SicaklikGostergesi,AraKatman,0,0,314,30,72,50);
	        		 line(AraKatman,s1,s2,348,72,makecol(255,0,0));
	        		 
	        		 blit(TemizVites,AraKatman,0,0,355,258,20,16);
	        		 textprintf_ex(AraKatman,font,362,262, makecol(255,255,255),-1,"%d",vites);
	        		 
	        		 blit(TemizToplamKm,AraKatman,0,0,389,220,66,20);
	        		 textprintf_ex(AraKatman,font,405,230, makecol(255,255,255),-1,"%.0fkm",toplamkm);
	        		 
	        		 blit(TemizKm,AraKatman,0,0,414,248,40,27);
	        		 textprintf_ex(AraKatman,font,415,260, makecol(255,255,255),-1,"%.0fkm",km);
	        		 
	        		 blit(AraKatman,screen,0,0,0,0,800,480);
	            	 
					       if(aci1>160)
	            		   aci1--;
	            		   if(aci1==160)
	            		   vites=1;
	            		   if(aci2>160)
	            		   aci2=aci2-2;
	            		   
	            		   if(aci4>272)
            			   aci4=aci4-0.2;
            			   if(aci4<272 && aci4>220)
            			   aci4=aci4-0.1;
					 }
				 }
		
				 if(aci1>160 && !key[KEY_UP] && !key[KEY_DOWN] && ElFreni==0 || aci2>160 && !key[KEY_UP] && !key[KEY_DOWN] && ElFreni==0 || 
				 aci4>220 && !key[KEY_UP] && !key[KEY_DOWN] && ElFreni==0 || motor==1 && !key[KEY_UP] && !key[KEY_DOWN] && ElFreni==0)
				 {
	 			       rest(90);
	 			       
	 			       if(aci4<221)
	 			       {
	 			       		motor=0;
	 			       		blit(Sicaklik2,AraKatman,0,0,339,95,22,19);
	 			       		blit(Motor1,AraKatman,0,0,249,251,26,18);
	        				blit(AraKatman,screen,0,0,0,0,800,480);
	 			       }
	 			       
	 			       benzinbitti:
	 			       motorarizasi:
	 			       	
  				 	   radyan1=float(aci1*3.14/180);
	       		 	   h1=cos(radyan1)*90+623;
		   		 	   h2=sin(radyan1)*90+185;
		   		 	   
		   		 			if(aci2<200 && aci1>160)
  	 						{
  	 							if(vites>1)
  	 							{
  	 								aci2=320;
  	 					   			vites--;
  	 							}	
  	 						}
		   		 	   
		   		 	   radyan2=float(aci2*3.14/180);
	    			   m1=cos(radyan2)*90+182;
   					   m2=sin(radyan2)*90+185;
   					   
   					   radyan4=float(aci4*3.14/180);
	    			   s1=cos(radyan4)*27+348;
	    			   s2=sin(radyan4)*27+72;
	    			   
	    			   	TOPLAM=fopen("ToplamKm.txt","r");
						fscanf(TOPLAM,"%f",&toplamkm);
						fclose(TOPLAM);
	    				
	    				if(aci1>160 && aci1<=195)
	    				{
						km=km+0.005;
						toplamkm=toplamkm+0.005;
						}
					 	else if(aci1>195 && aci1<=230)
					 	{
						km=km+0.016;
						toplamkm=toplamkm+0.016;
						}
					 	else if(aci1>230 && aci1<=270)
					 	{
						km=km+0.026;
						toplamkm=toplamkm+0.026;
						}
					 	else if(aci1>270 && aci1<=305)
					 	{
						km=km+0.038;
						toplamkm=toplamkm+0.038;
						}
					 	else if(aci1>305 && aci1<=343)
					 	{
						km=km+0.05;
						toplamkm=toplamkm+0.05;
						}
					 	else if(aci1>343 && aci1<=380)
					 	{
					 	km=km+0.06;
						toplamkm=toplamkm+0.06;
					 	}
						
						TOPLAM=fopen("ToplamKm.txt","w+");
						fprintf(TOPLAM,"%.3f",toplamkm);
						fclose(TOPLAM);
	    	
	    		 	   blit(HizGostergesi,AraKatman,0,0,514,62,800,320);
	       		 	   line(AraKatman,h1,h2,623,185,makecol(255,0,0));
	       		 	   
	       		 	   blit(MotorGostergesi,AraKatman,0,0,60,68,239,156);
	        		   line(AraKatman,m1,m2,182,185,makecol(255,0,0));
	        		   
	        		   blit(SicaklikGostergesi,AraKatman,0,0,314,30,72,50);
	        		   line(AraKatman,s1,s2,348,72,makecol(255,0,0));
	        		   
	        		   blit(TemizVites,AraKatman,0,0,355,258,20,16);
	        		   textprintf_ex(AraKatman,font,362,262, makecol(255,255,255),-1,"%d",vites);
	        		   
	        		   blit(TemizToplamKm,AraKatman,0,0,389,220,66,20);
	        		   textprintf_ex(AraKatman,font,405,230, makecol(255,255,255),-1,"%.0fkm",toplamkm);
	        		   
	        		   blit(TemizKm,AraKatman,0,0,414,248,40,27);
	        		   textprintf_ex(AraKatman,font,415,260, makecol(255,255,255),-1,"%.0fkm",km);
	        		 
	       		 	   blit(AraKatman,screen,0,0,0,0,800,480);
	       		 	   
			  		      if(aci1>160)
            			  aci1--;
            			  if(aci2>160)
            			  aci2=aci2-3;	  
						  
						  if(aci4>272)
            			  aci4=aci4-0.2;
            			  if(aci4<272 && aci4>220)
            			  aci4=aci4-0.1; 
   				 }
	}
	
	void benzindoldur()
	{
		if(key[KEY_B])
   				{
   					aci3=320;
   					benzin=0;
   					
   					radyan3=float(aci3*3.14/180);
	    			b1=cos(radyan3)*27+456;
	    			b2=sin(radyan3)*27+72;
	    			
					blit(Benzin2,AraKatman,0,0,446,95,22,19);
					blit(BenzinGostergesi,AraKatman,0,0,424,26,64,53);
					line(AraKatman,b1,b2,456,72,makecol(255,0,0));
        			blit(AraKatman,screen,0,0,0,0,800,480);
   				}
	}
	
	void kemer()
	{
			if(key[KEY_E])
 				{
 					switch(EmniyetKemeri)
 					{
 						case 0: blit(EmniyetKemeri1,AraKatman,0,0,203,224,17,23); stop_sample(EmniyetSesi); EmniyetKemeri=1; break;
 						case 1: blit(EmniyetKemeri2,AraKatman,0,0,203,224,17,23); 
					 	play_sample(EmniyetSesi,255/*ses seviyesi*/,128/*sað ya da sol hoparlör ayarý*/,1000/*ses hýzý ayarý*/,1); EmniyetKemeri=0; break;
 					}
 					rest(200);
 					blit(AraKatman,screen,0,0,0,0,800,480);
 				}
	}
	
	void fren()
	{
		if(key[KEY_SPACE])
 				{
				 	switch(ElFreni)
 					{
 						case 0: blit(ElFreni2,AraKatman,0,0,150,226,19,17); ElFreni=1; break;
 						case 1: blit(ElFreni1,AraKatman,0,0,150,226,19,17); ElFreni=0; break;
 					}
 					rest(200);
 					blit(AraKatman,screen,0,0,0,0,800,480);
 				}
	}
	
	void sisler()
	{
		if(key[KEY_O])
		{
 		    switch(OnSis)
			{
 				case 0: blit(OnSis2,AraKatman,0,0,682,248,25,20); OnSis=1; break;
 				case 1: blit(OnSis1,AraKatman,0,0,682,248,25,20); OnSis=0; break;
			}
			rest(200);
			blit(AraKatman,screen,0,0,0,0,800,480);
		}
 			
		if(key[KEY_L])
 		{
			switch(ArkaSis)
			{
 				case 0: blit(ArkaSis2,AraKatman,0,0,651,248,25,20); ArkaSis=1; break;
 				case 1: blit(ArkaSis1,AraKatman,0,0,651,248,25,20); ArkaSis=0; break;
			}
			rest(200);
			blit(AraKatman,screen,0,0,0,0,800,480);
		}
	}
	
	void farlar()
	{
		if(key[KEY_U])
		{
 				switch(UzunFar)
 				{
 					case 0: blit(UzunFar2,AraKatman,0,0,529,250,27,19); blit(KisaFar1,AraKatman,0,0,564,249,25,20); UzunFar=1; KisaFar=0; break;
 					case 1: blit(UzunFar1,AraKatman,0,0,529,250,27,19); UzunFar=0; break;
 				}
 				rest(200);
 				blit(AraKatman,screen,0,0,0,0,800,480);
		}
 			
		if(key[KEY_K])
		{
 				switch(KisaFar)
 				{
 					case 0: blit(KisaFar2,AraKatman,0,0,564,249,25,20); blit(UzunFar1,AraKatman,0,0,529,250,27,19); KisaFar=1; UzunFar=0; break;
 					case 1: blit(KisaFar1,AraKatman,0,0,564,249,25,20); KisaFar=0; break;
 				}
 				rest(200);
 				blit(AraKatman,screen,0,0,0,0,800,480);
		}
	}
	
	void sinyaller()
		{
  		        if(key[KEY_LEFT])
 				{
                 solsinyal=true;
                 play_sample(Sinyal,255/*ses seviyesi*/,128/*sað ya da sol hoparlör ayarý*/,1000/*ses hýzý ayarý*/,1);
                 }
                 
 				if(key[KEY_LEFT] && solsinyal==true && !key[KEY_RIGHT])
				 {		
 						blit(SolSinyal2,AraKatman,0,0,265,36,31,26);
				 		blit(AraKatman,screen,0,0,0,0,800,480);
 						rest(400);
						blit(SolSinyal1,AraKatman,0,0,265,36,31,26);
						blit(AraKatman,screen,0,0,0,0,800,480);
						rest(400);
 				}
 				
				solsinyal=false;
	 			stop_sample(Sinyal);           
 				
				if(key[KEY_RIGHT])
 				{
                 sagsinyal=true;
                 play_sample(Sinyal,255/*ses seviyesi*/,128/*sað ya da sol hoparlör ayarý*/,1000/*ses hýzý ayarý*/,1);
     			 }
                 
 				if(key[KEY_RIGHT] && sagsinyal==true && !key[KEY_LEFT])
				 {		
 						blit(SagSinyal2,AraKatman,0,0,510,34,31,26);
				 		blit(AraKatman,screen,0,0,0,0,800,480);
 						rest(400);
						blit(SagSinyal1,AraKatman,0,0,510,34,31,26);
						blit(AraKatman,screen,0,0,0,0,800,480);
						rest(400);
 				}
 				
				sagsinyal=false;
	 			stop_sample(Sinyal);
		}
		
		void dortluler()
		{
			    if(key[KEY_LEFT] && key[KEY_RIGHT])
 				{
 					dortsinyal=true;
 					play_sample(Dortlu,255/*ses seviyesi*/,128/*sað ya da sol hoparlör ayarý*/,1000/*ses hýzý ayarý*/,0);
		        }
		        else
		        {
		        	dortsinyal=false;
 					stop_sample(Dortlu);
		        }
				
				if(key[KEY_LEFT] && key[KEY_RIGHT] && dortsinyal==true)
				{
 						blit(SagSinyal2,AraKatman,0,0,510,34,31,26);
 						blit(SolSinyal2,AraKatman,0,0,265,36,31,26);
				 		blit(AraKatman,screen,0,0,0,0,800,480);
 						rest(400);
						blit(SagSinyal1,AraKatman,0,0,510,34,31,26);
						blit(SolSinyal1,AraKatman,0,0,265,36,31,26);
						blit(AraKatman,screen,0,0,0,0,800,480);
						rest(400);
 				}
		}
	
};

class Radio : public Araba{
	public:
	void radyoon()
	{
		if(key[KEY_R])
 				{
				 	blit(Radyo2,AraKatman,0,0,111,246,18,21);
				 	
			 		textprintf_ex(AraKatman,font,610,370, makecol(0,255,0),-1,"1- Nilufer");
			 		textprintf_ex(AraKatman,font,610,385, makecol(0,255,0),-1,"2- Aman Aman");
			 		textprintf_ex(AraKatman,font,610,400, makecol(0,255,0),-1,"3- Bye Bye Love");
			 		textprintf_ex(AraKatman,font,610,415, makecol(0,255,0),-1,"4- Albatraoz");
			 		
				 		if(key[KEY_1_PAD])
				 		{
				 			stop_sample(Nilufer);
				 			stop_sample(AmanAman);
				 			stop_sample(ByeByeLove);
				 			stop_sample(Albatraoz);
				 			stop_sample(MotorSesi);
			 				play_sample(Nilufer,100/*ses seviyesi*/,128/*sað ya da sol hoparlör ayarý*/,1000/*ses hýzý ayarý*/,1);
			 				play_sample(MotorSesi,15/*ses seviyesi*/,128/*sað ya da sol hoparlör ayarý*/,1000/*ses hýzý ayarý*/,1);
			 				blit(RadyoButton,AraKatman,0,0,590,366,15,15);
			 				
			 				blit(RadyoButtonSil,AraKatman,0,0,590,381,15,15);
			 				blit(RadyoButtonSil,AraKatman,0,0,590,396,15,15);
			 				blit(RadyoButtonSil,AraKatman,0,0,590,411,15,15);
				 		}
				 			
			 			if(key[KEY_2_PAD])
				 		{
				 			stop_sample(Nilufer);
				 			stop_sample(AmanAman);
				 			stop_sample(ByeByeLove);
				 			stop_sample(Albatraoz);
				 			stop_sample(MotorSesi);
				 			play_sample(AmanAman,100/*ses seviyesi*/,128/*sað ya da sol hoparlör ayarý*/,1000/*ses hýzý ayarý*/,1);	
				 			play_sample(MotorSesi,15/*ses seviyesi*/,128/*sað ya da sol hoparlör ayarý*/,1000/*ses hýzý ayarý*/,1);
				 			blit(RadyoButton,AraKatman,0,0,590,381,15,15);
				 			
				 			blit(RadyoButtonSil,AraKatman,0,0,590,366,15,15);
			 				blit(RadyoButtonSil,AraKatman,0,0,590,396,15,15);
			 				blit(RadyoButtonSil,AraKatman,0,0,590,411,15,15);
		 				}
		 					
	 					if(key[KEY_3_PAD])
				 		{
 						  	stop_sample(Nilufer);
				 			stop_sample(AmanAman);
				 			stop_sample(ByeByeLove);
				 			stop_sample(Albatraoz);
				 			stop_sample(MotorSesi);
				 			play_sample(ByeByeLove,100/*ses seviyesi*/,128/*sað ya da sol hoparlör ayarý*/,1000/*ses hýzý ayarý*/,1);	
				 			play_sample(MotorSesi,15/*ses seviyesi*/,128/*sað ya da sol hoparlör ayarý*/,1000/*ses hýzý ayarý*/,1);
				 			blit(RadyoButton,AraKatman,0,0,590,396,15,15);
				 			
				 			blit(RadyoButtonSil,AraKatman,0,0,590,366,15,15);
			 				blit(RadyoButtonSil,AraKatman,0,0,590,381,15,15);
			 				blit(RadyoButtonSil,AraKatman,0,0,590,411,15,15);
		 				}
		 				
				 		if(key[KEY_4_PAD])
				 		{
						    stop_sample(Nilufer);
				 			stop_sample(AmanAman);
				 			stop_sample(ByeByeLove);
				 			stop_sample(Albatraoz);
				 			stop_sample(MotorSesi);
				 			play_sample(Albatraoz,100/*ses seviyesi*/,128/*sað ya da sol hoparlör ayarý*/,1000/*ses hýzý ayarý*/,1);
				 			play_sample(MotorSesi,15/*ses seviyesi*/,128/*sað ya da sol hoparlör ayarý*/,1000/*ses hýzý ayarý*/,1);
				 			blit(RadyoButton,AraKatman,0,0,590,411,15,15);
				 			
				 			blit(RadyoButtonSil,AraKatman,0,0,590,366,15,15);
				 			blit(RadyoButtonSil,AraKatman,0,0,590,381,15,15);
			 				blit(RadyoButtonSil,AraKatman,0,0,590,396,15,15);
		 				}
 					
 					blit(AraKatman,screen,0,0,0,0,800,480);
				}
	}
	
	void radyooff()
	{
		if(key[KEY_F])
			 	{
			 		blit(Radyo1,AraKatman,0,0,111,246,18,21);
			 		stop_sample(Nilufer);
				 	stop_sample(AmanAman);
				 	stop_sample(ByeByeLove);
					stop_sample(Albatraoz);
					
					textprintf_ex(AraKatman,font,610,370, makecol(0,0,0),-1,"1- Nilufer");
			 		textprintf_ex(AraKatman,font,610,385, makecol(0,0,0),-1,"2- Aman Aman");
			 		textprintf_ex(AraKatman,font,610,400, makecol(0,0,0),-1,"3- Bye Bye Love");
			 		textprintf_ex(AraKatman,font,610,415, makecol(0,0,0),-1,"4- Albatraoz");
			 		
			 		blit(RadyoButtonSil,AraKatman,0,0,590,366,15,15);
			 		blit(RadyoButtonSil,AraKatman,0,0,590,381,15,15);
			 		blit(RadyoButtonSil,AraKatman,0,0,590,396,15,15);
			 		blit(RadyoButtonSil,AraKatman,0,0,590,411,15,15);
			 		blit(AraKatman,screen,0,0,0,0,800,480);
				}
	}
		
};

class Horn : public Radio{
	
	public:
	void kornaon()
	{
		if(key[KEY_Q])
		{
  		     blit(Korna2,AraKatman,0,0,143,249,24,19);
 			 blit(AraKatman,screen,0,0,0,0,800,480);
		     play_sample(KornaSesi,150/*ses seviyesi*/,128/*sað ya da sol hoparlör ayarý*/,1000/*ses hýzý ayarý*/,0);
   			 rest(200);
		}
	}
	
	void kornaoff()
	{
		stop_sample(KornaSesi);
		blit(Korna1,AraKatman,0,0,143,249,24,19);
		blit(AraKatman,screen,0,0,0,0,800,480);
	}
};

int main()
{
	baslat();
 	show_mouse(screen);
 	set_window_title("TOYOTA AURIS 2007");
 	
 	Horn auris;

 	while(!key[KEY_ESC])
 	{
 		auris.arackapali();
 		auris.benzindoldur();
 		
 		if(mouse_x>250 && mouse_x<350 && mouse_y>350 && mouse_y<450 && (mouse_b & 1))				//START BUTTON
 		{
 			auris.aracacik();
 			
 			while(!(mouse_x>450 && mouse_x<550 && mouse_y>350 && mouse_y<450 && (mouse_b & 1)))		//STOPA BASANA KADAR ÇALIÞTIR
 			{
 				auris.hareket();				
 				auris.benzindoldur();				
 				auris.kemer();				
 				auris.fren();
 				auris.sisler();	
 				auris.farlar();
 				auris.kornaon();
 				auris.kornaoff();
 				auris.sinyaller();
 				auris.dortluler();
 				auris.radyoon();
 				auris.radyooff();
 			}
 			
 			auris.arackapali();
 		}
 	}
 	
 	bitir();
 	return 0;
 }
END_OF_MAIN();

void baslat()
{
	int depth, res;
	allegro_init();
	depth = desktop_color_depth();
	
	if (depth == 0) depth = 32;
	set_color_depth(depth);
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,480,0,0);
	
	if (res != 0) 
	{
		allegro_message(allegro_error);
		exit(-1);
	}

	install_timer();
	install_keyboard();
	install_mouse();
	install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,"A");
}

void bitir()
{
	clear_keybuf();
}
