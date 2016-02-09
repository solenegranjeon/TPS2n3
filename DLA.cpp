
// ===========================================================================
//                                  Includes
// ===========================================================================

#include "DLA.h"

// ===========================================================================
//                       Definition of static attributes
// ===========================================================================

// ===========================================================================
//                                Constructors
// ===========================================================================
DLA::DLA(){
	tab = nullptr;
	L = 0;

}

DLA::DLA(const DLA& im){
	L = im.L;
	tab = new int*[L];
	for(int i = 0; i<L; i++){
		tab[i]= new int[L];
	}
	for(int x = 0; x<L; x++){
		for(int y = 0; y<L; y++){
			tab[x][y]=im.tab[x][y];
		}
	}
}

DLA::DLA(int size ,int xi,int yi){
	L=size;
	
	tab = new int*[L];
	for(int i = 0; i<L; i++){
		tab[i]= new int[L];
	}
	for(int x = 0; x<L; x++){
		for(int y = 0; y<L; y++){
			tab[x][y]=0;
		}
	}
	tab[xi][yi]=1;


}

// ===========================================================================
//                                 Destructor
// ===========================================================================
DLA::~DLA() {
	for(int i = 0; i<L; i++){
		delete[] tab[i];
	}
	delete[] tab;
}

// ===========================================================================
//                               Public Methods
// ===========================================================================

void DLA::newParticle(void){
	
	//Initialisation de la particule
	int* pos = new int[2];
	pos[0]=L/4;
	pos[1]=L/4;
	
	bool done = false;
	
	while(done==false){
		
		//Random Move 0:W 1:N 2:E 3:S
		int randchoice = rand() % 4 ;
		if(randchoice == 0){
			pos[0] -= 1;
		}
		if(randchoice == 1){
			pos[1] += 1;
		}
		if(randchoice == 2){
			pos[0] += 1;
		}
		if(randchoice == 3){
			pos[1] -= 1;
		}
		
		//if out, start again on initial position
		if(pos[0]<0 or pos[0]>=L or pos[1]<0 or pos[1]>=L){
			pos[0]=L/4;
			pos[1]=L/4;
		}
		
		//else if next to particle, stop and add 1 at this position in tab
		
		else{

			bool next_to_part = false;
			
			if(pos[0]>0){
				if(tab[pos[0]-1][pos[1]] == 1){
					next_to_part = true ;
				}
			}
			if(pos[0]<L-1){
				if(tab[pos[0]+1][pos[1]] == 1){
					next_to_part = true ;
				}
			}
			if(pos[1]>0){
				if(tab[pos[0]][pos[1]-1] == 1){
					next_to_part = true ;
				}
			}
			if(pos[1]<L-1){
				if(tab[pos[0]][pos[1]+1] == 1){
					next_to_part = true ;
				}
			}
			
			if(next_to_part==true){
				tab[pos[0]][pos[1]]=1;
				done = true;
			}
			
		}
	}
	delete[] pos;
	
}

void DLA::mainMethod(void){
	
	bool done = false;
	int pos = L/4;
	int iter = 0;
	
	while(done == false){
		
		//Add new particle
		this->newParticle();
		
		//Check if the initial position is next to a particle
		if(tab[pos +1][pos]==1 or tab[pos-1][pos]==1 or tab[pos][pos+1]==1 or tab[pos][pos-1]==1){
			done = true;
		}
		
	}

}

void DLA::display(void){
	for(int x = 0; x<L; x++){
		for(int y = 0; y<L; y++){
			printf("%d ", tab[x][y]);
		}
		printf("\n");
	}

}


// ===========================================================================
//                              Protected Methods
// ===========================================================================

// ===========================================================================
//                              External Methods
// ===========================================================================
