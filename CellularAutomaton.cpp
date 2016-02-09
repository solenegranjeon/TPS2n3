
// ===========================================================================
//                                  Includes
// ===========================================================================

#include "CellularAutomaton.h"

// ===========================================================================
//                       Definition of static attributes
// ===========================================================================

// ===========================================================================
//                                Constructors
// ===========================================================================
CellularAutomaton::CellularAutomaton(){
	tab = nullptr;
	size = 0;
	iter = 0;
	save = nullptr;
}

CellularAutomaton::CellularAutomaton(const CellularAutomaton& ca){
	size = ca.size;
	iter = ca.iter;
	tab = new int[size];
	for( int i=0; i<size; i++){
		tab[i]= ca.tab[i];
	}
	save = new int*[size];
	for (int t = 0; t< iter; t++){
		memcpy(save[t], ca.save[t], sizeof(int)*size);
	}
}

CellularAutomaton::CellularAutomaton(int N, int it){
	size = N;
	iter = it;
	tab = new int[size];
	for( int i=0; i<size; i++){
		tab[i]= 0;
	}
	tab[(int)N/2] = 1;
	
	save = new int*[size];
	for(int t=0; t<iter; t++){
		save[t] = new int[size];
	}
	memcpy(save[0], tab, sizeof(int)*size);
	
}

// ===========================================================================
//                                 Destructor
// ===========================================================================
CellularAutomaton::~CellularAutomaton() {
	delete[] tab;
	delete[] save;
	tab = nullptr;
	save = nullptr;
}

// ===========================================================================
//                               Public Methods
// ===========================================================================

void CellularAutomaton::Tn(void){
	
	int* etat_actuel = new int[size];
	memcpy(etat_actuel, tab, sizeof(int)*size);
	
	if(etat_actuel[size]==1 && etat_actuel[0]==1 && etat_actuel[1]==1){
		tab[0]=0;
	}
	if(etat_actuel[size]==1 && etat_actuel[0]==1 && etat_actuel[1]==0){
		tab[0]=0;
	}
	if(etat_actuel[size]==1 && etat_actuel[0]==0 && etat_actuel[1]==1){
		tab[0]=0;
	}
	if(etat_actuel[size]==1 && etat_actuel[0]==0 && etat_actuel[1]==0){
		tab[0]=1;
	}
	if(etat_actuel[size]==0 && etat_actuel[0]==1 && etat_actuel[1]==1){
		tab[0]=1;
	}
	if(etat_actuel[size]==0 && etat_actuel[0]==1 && etat_actuel[1]==0){
		tab[0]=1;
	}
	if(etat_actuel[size]==0 && etat_actuel[0]==0 && etat_actuel[1]==1){
		tab[0]=1;
	}
	if(etat_actuel[size]==0 && etat_actuel[0]==0 && etat_actuel[1]==0){
		tab[0]=0;
	}
	
	for(int i = 1; i<size-1; i++){
		if(etat_actuel[i-1]==1 && etat_actuel[i]==1 && etat_actuel[i+1]==1){
			tab[i]=0;
		}
		if(etat_actuel[i-1]==1 && etat_actuel[i]==1 && etat_actuel[i+1]==0){
			tab[i]=0;
		}
		if(etat_actuel[i-1]==1 && etat_actuel[i]==0 && etat_actuel[i+1]==1){
			tab[i]=0;
		}
		if(etat_actuel[i-1]==1 && etat_actuel[i]==0 && etat_actuel[i+1]==0){
			tab[i]=1;
		}
		if(etat_actuel[i-1]==0 && etat_actuel[i]==1 && etat_actuel[i+1]==1){
			tab[i]=1;
		}
		if(etat_actuel[i-1]==0 && etat_actuel[i]==1 && etat_actuel[i+1]==0){
			tab[i]=1;
		}
		if(etat_actuel[i-1]==0 && etat_actuel[i]==0 && etat_actuel[i+1]==1){
			tab[i]=1;
		}
		if(etat_actuel[i-1]==0 && etat_actuel[i]==0 && etat_actuel[i+1]==0){
			tab[i]=0;
		}
	}
	
	if(etat_actuel[size-1]==1 && etat_actuel[size]==1 && etat_actuel[0]==1){
		tab[size]=0;
	}
	if(etat_actuel[size-1]==1 && etat_actuel[size]==1 && etat_actuel[0]==0){
		tab[size]=0;
	}
	if(etat_actuel[size-1]==1 && etat_actuel[size]==0 && etat_actuel[0]==1){
		tab[size]=0;
	}
	if(etat_actuel[size-1]==1 && etat_actuel[size]==0 && etat_actuel[0]==0){
		tab[size]=1;
	}
	if(etat_actuel[size-1]==0 && etat_actuel[size]==1 && etat_actuel[0]==1){
		tab[size]=1;
	}
	if(etat_actuel[size-1]==0 && etat_actuel[size]==1 && etat_actuel[0]==0){
		tab[size]=1;
	}
	if(etat_actuel[size-1]==0 && etat_actuel[size]==0 && etat_actuel[0]==1){
		tab[size]=1;
	}
	if(etat_actuel[size-1]==0 && etat_actuel[size]==0 && etat_actuel[0]==0){
		tab[size]=0;
	}
	delete[] etat_actuel;
	
}

void CellularAutomaton::fill_save(void){
	for(int t = 1; t<iter; t++){
		this->Tn();
		memcpy(this->save[t], this->tab, sizeof(int)*size);
	}
}

//~ CellularAutomaton CellularAutomaton::Tn(void){
	//~ 
	//~ CellularAutomaton res = CellularAutomaton();
	//~ res.size = size;
	//~ res.tab = new int[size];
	//~ for( int i=0; i<size; i++){
		//~ res.tab[i]= tab[i];
	//~ }
//~ 
	//~ if(this->tab[size]==1 && this->tab[0]==1 && this->tab[1]==1){
		//~ res.tab[0]=0;
	//~ }
	//~ if(this->tab[size]==1 && this->tab[0]==1 && this->tab[1]==0){
		//~ res.tab[0]=0;
	//~ }
	//~ if(this->tab[size]==1 && this->tab[0]==0 && this->tab[1]==1){
		//~ res.tab[0]=0;
	//~ }
	//~ if(this->tab[size]==1 && this->tab[0]==0 && this->tab[1]==0){
		//~ res.tab[0]=1;
	//~ }
	//~ if(this->tab[size]==0 && this->tab[0]==1 && this->tab[1]==1){
		//~ res.tab[0]=1;
	//~ }
	//~ if(this->tab[size]==0 && this->tab[0]==1 && this->tab[1]==0){
		//~ res.tab[0]=1;
	//~ }
	//~ if(this->tab[size]==0 && this->tab[0]==0 && this->tab[1]==1){
		//~ res.tab[0]=1;
	//~ }
	//~ if(this->tab[size]==0 && this->tab[0]==0 && this->tab[1]==0){
		//~ res.tab[0]=0;
	//~ }
	//~ 
	//~ for(int i = 1; i<size-1; i++){
		//~ if(this->tab[i-1]==1 && this->tab[i]==1 && this->tab[i+1]==1){
			//~ res.tab[i]=0;
		//~ }
		//~ if(this->tab[i-1]==1 && this->tab[i]==1 && this->tab[i+1]==0){
			//~ res.tab[i]=0;
		//~ }
		//~ if(this->tab[i-1]==1 && this->tab[i]==0 && this->tab[i+1]==1){
			//~ res.tab[i]=0;
		//~ }
		//~ if(this->tab[i-1]==1 && this->tab[i]==0 && this->tab[i+1]==0){
			//~ res.tab[i]=1;
		//~ }
		//~ if(this->tab[i-1]==0 && this->tab[i]==1 && this->tab[i+1]==1){
			//~ res.tab[i]=1;
		//~ }
		//~ if(this->tab[i-1]==0 && this->tab[i]==1 && this->tab[i+1]==0){
			//~ res.tab[i]=1;
		//~ }
		//~ if(this->tab[i-1]==0 && this->tab[i]==0 && this->tab[i+1]==1){
			//~ res.tab[i]=1;
		//~ }
		//~ if(this->tab[i-1]==0 && this->tab[i]==0 && this->tab[i+1]==0){
			//~ res.tab[i]=0;
		//~ }
	//~ }
	//~ 
	//~ if(this->tab[size-1]==1 && this->tab[size]==1 && this->tab[0]==1){
		//~ res.tab[size]=0;
	//~ }
	//~ if(this->tab[size-1]==1 && this->tab[size]==1 && this->tab[0]==0){
		//~ res.tab[size]=0;
	//~ }
	//~ if(this->tab[size-1]==1 && this->tab[size]==0 && this->tab[0]==1){
		//~ res.tab[size]=0;
	//~ }
	//~ if(this->tab[size-1]==1 && this->tab[size]==0 && this->tab[0]==0){
		//~ res.tab[size]=1;
	//~ }
	//~ if(this->tab[size-1]==0 && this->tab[size]==1 && this->tab[0]==1){
		//~ res.tab[size]=1;
	//~ }
	//~ if(this->tab[size-1]==0 && this->tab[size]==1 && this->tab[0]==0){
		//~ res.tab[size]=1;
	//~ }
	//~ if(this->tab[size-1]==0 && this->tab[size]==0 && this->tab[0]==1){
		//~ res.tab[size]=1;
	//~ }
	//~ if(this->tab[size-1]==0 && this->tab[size]==0 && this->tab[0]==0){
		//~ res.tab[size]=0;
	//~ }
	//~ 
//~ }


// ===========================================================================
//                              Protected Methods
// ===========================================================================

// ===========================================================================
//                              External Methods
// ===========================================================================

