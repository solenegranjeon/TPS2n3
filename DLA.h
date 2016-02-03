
#ifndef DLA_H__
#define DLA_H__

// ===========================================================================
//                                  Includes
// ===========================================================================

#include <fstream>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

#include "ImagePPM.h"

using namespace std;

class DLA {
 public :
  // =========================================================================
  //                               Constructors
  // =========================================================================
  DLA();
  DLA(const DLA&);
  DLA(int,int,int);  

  // =========================================================================
  //                                Destructor
  // =========================================================================
  virtual ~DLA();

  // =========================================================================
  //                                  Getters
  // =========================================================================
	

  // =========================================================================
  //                                  Setters
  // =========================================================================


  // =========================================================================
  //                                 Operators
  // =========================================================================



  // =========================================================================
  //                              Public Methods
  // =========================================================================

	void newParticle(void);
	void mainMethod(void);
	void display(void);



	protected :
  // =========================================================================
  //                             Protected Methods
  // =========================================================================

  // =========================================================================
  //                                Attributes
  // =========================================================================

	int L;
	int** tab;


};


// ===========================================================================
//                            Getters' definitions
// ===========================================================================


// ===========================================================================
//                            Setters' definitions
// ===========================================================================

// ===========================================================================
//                           Operators' definitions
// ===========================================================================

// ===========================================================================
//                        Inline functions' definition
// ===========================================================================



#endif



