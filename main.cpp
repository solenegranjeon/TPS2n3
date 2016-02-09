//http://liris.cnrs.fr/~crocaber/3Bim/

// ===========================================================================
//                                  Includes
// ===========================================================================
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <ctime>

#include "DLA.h"
#include "ImagePPM.h"
#include "CellularAutomaton.h"


using namespace std;


// ===========================================================================
//                            Function declarations
// ===========================================================================


// ===========================================================================
//                                    MAIN
// ===========================================================================

int main(int argc,char* argv[]){
	srand(time(NULL));
	DLA* dla1 = new DLA(100,75,75);
	dla1->mainMethod();
	
	ImagePPM* miracle = new ImagePPM(100,dla1->tab);
	miracle->save("test.ppm");
		
	delete dla1;
	delete miracle;
	
	CellularAutomaton cell_A = CellularAutomaton(400,400);
	cell_A.fill_save();
	
	ImagePPM* miracle2 = new ImagePPM(400,cell_A.save);
	miracle2->save("CellAutom.ppm");
	delete miracle2;
	
	return 0;
}


