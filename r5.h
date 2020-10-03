/*
class           license
type            GLORYWARE
ipname          R5
author          Ray Edward Bornert II
aka             Riitoken
date            2013-APR-22 MON
copyright       2013-2020 Riitoken, All rights reserved.
royalty         Free
warranty        As is
rules           https://docs.google.com/document/d/1xAZ-WAHxwBuu1H-LszPGuMQXLryebBYzBdrHzV2Gom0
cppsrc          begintext
*/

#ifndef _r5_h_
#define _r5_h_

#include <map>
#include <vector>
#include <string>

namespace r5 {

namespace r5t {

  typedef   signed            char  inta; // 1 == sizeof(inta)
  typedef   signed short       int  intb; // 2 == sizeof(intb)
  typedef   signed long        int  intc; // 4 == sizeof(intc)
  typedef   signed long long   int  intd; // 8 == sizeof(intd)
//typedef   signed quad        int  inte; //16 == sizeof(inte)
  typedef unsigned            char  unta; // 1 == sizeof(unta)
  typedef unsigned short       int  untb; // 2 == sizeof(untb)
  typedef unsigned long        int  untc; // 4 == sizeof(untc)
  typedef unsigned long long   int  untd; // 8 == sizeof(untd)
//typedef unsigned quad        int  unte; //16 == sizeof(unte)
//typedef          tiny      float  floa; // 1 == sizeof(floa)
//typedef          short     float  flob; // 2 == sizeof(flob)
  typedef                    float  floc; // 4 == sizeof(floc)
  typedef                   double  flod; // 8 == sizeof(flod)
//typedef                    fquad  floe; //16 == sizeof(floe)

bool is_valid_types();

}; // end namespace r5t


typedef std::map<std::string,std::string> lvalrval_m;
typedef std::vector<lvalrval_m> r5_v;

int load_file( const std::string& fn, r5_v& v );
int fprint( lvalrval_m& m, FILE* fp=stdout, const size_t pad=15 );
int fprint( r5_v& v, FILE* fp=stdout );

}; // end namespace r5

#endif

/*
endtext
endclass
*/
