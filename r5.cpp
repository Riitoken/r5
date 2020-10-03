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

#include "r5.h"
using namespace std;

namespace r5 {

namespace r5t {

bool is_valid_types()
{
  return(true
  && ( 1 == sizeof(inta) )
  && ( 2 == sizeof(intb) )
  && ( 4 == sizeof(intc) )
  && ( 8 == sizeof(intd) )
//&& (16 == sizeof(inte) )
  && ( 1 == sizeof(unta) )
  && ( 2 == sizeof(untb) )
  && ( 4 == sizeof(untc) )
  && ( 8 == sizeof(untd) )
//&& (16 == sizeof(unte) )
//&& ( 1 == sizeof(floa) )
//&& ( 2 == sizeof(flob) )
  && ( 4 == sizeof(floc) )
  && ( 8 == sizeof(flod) )
//&& (16 == sizeof(floe) )
  );
}

}; // end namespace r5t


int load_file( const std::string& fn, r5_v& v )
{
	FILE* fp = fopen(fn.c_str(),"r");
	if(NULL==fp)
		return -1;

	lvalrval_m lrm;

	char line[128];
	char lval[128];
	char rval[128];

	bool istext=false;
	string ls = "";
	string rs = "";

	while(!feof(fp))
	{
		line[0]=0;
		if(NULL==fgets(line,sizeof(line),fp))
			break;

		if(true==istext)
		{
			rs+=line;
			lval[0]=0;
			int result = sscanf(line,"%[^\r\n]s",lval);
			if(0==strncmp(lval,"endtext",7))
			{
				lrm[ls]=rs;
				istext=false;
			}
			continue;
		}

		if(' '>line[0])
			continue;

		lval[0]=rval[0]=0;
		int result = sscanf(line,"%s %[^\r\n]s",lval,rval);
		if(0>=result)
			continue;

		ls = lval;
		rs = rval;
		if(ls <= " ") continue;

		if(rs=="begintext")
		{
			rs += "\n"; 
			istext=true;
			continue;
		}

		if(ls=="class") // new class
		{
			if(0<lrm.size())
			{
				lrm["endclass"]="";
				v.push_back(lrm);
			}
			lrm.clear();
			lrm[ls]=rs;
			continue;
		}

		if(ls=="endclass")
		{
			if(0<lrm.size())
			{
				lrm[ls]=rs;
				v.push_back(lrm);
			}
			lrm.clear();
			continue;
		}

		if(0<lrm.size())
		{
			lrm[ls]=rs;
		}
	}
	fclose(fp);

	// need this in case endclass missing
	if(0 < lrm.size() && lrm["class"] > " ")
	{
		lrm["endclass"]="";
		v.push_back(lrm);
	}
	lrm.clear();

	return (int)v.size();

} // end function load_file

int fprint( lvalrval_m& m, FILE* fp, const size_t pad )
{
	if(NULL==fp)return -1;

	size_t len;
	string S;

			S="class"	; len=S.length(); for(int i=0;i<len;i++)fputc(S[i],fp); fputc(' ' ,fp); for(int i=len;i<pad;i++) fputc(' ',fp);
			S=m[S]		; len=S.length(); for(int i=0;i<len;i++)fputc(S[i],fp); fputc('\n',fp);
		
	for(auto &f : m) // for each field in the class
	{
		// c++ maps do not preserve original file line order
		if((f.first != "class") && (f.first != "endclass"))
		{
			S=f.first	; len=S.length(); for(int i=0;i<len;i++)fputc(S[i],fp); fputc(' ' ,fp); for(int i=len;i<pad;i++) fputc(' ',fp);
			S=f.second	; len=S.length(); for(int i=0;i<len;i++)fputc(S[i],fp); fputc('\n',fp);
		}
	}
			S="endclass"; len=S.length(); for(int i=0;i<len;i++)fputc(S[i],fp); fputc(' ' ,fp); for(int i=len;i<pad;i++) fputc(' ',fp);
			S=m[S]		; len=S.length(); for(int i=0;i<len;i++)fputc(S[i],fp); fputc('\n',fp);

	return 0;
}

int fprint( r5_v& v, FILE* fp )
{
	if(NULL==fp)return -1;
	for(auto &c : v) // for each class in the map
	{
		string cn = c["class"];
		if(cn <= " ")continue;
		fprint(c,fp);
		fputc('\n',fp);	
	}
	return 0;
} // end function sprint

}; // end namespace r5

/*
endtext
endclass
*/
