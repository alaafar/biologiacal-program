#include "PROTEIN.h"
#include "Sequence.h"
#include "RNA.h"
#include <bits/stdc++.h>
Protein::Protein() {}
Protein::~Protein()
{
delete [] seq ;
}
void Protein::Print()
{
    cout << "TYPE IS" <<type << endl ;
}
Protein::Protein(char* p , Protein_Type atype , int l)
{
    seq = p ;
    type = atype ;
    length = l  ;

}
/*
DNA* Protein::GetDNAStrandsEncodingMe(const DNA & bigDNA){
    CodonsTable c  ;
    DNA D ;
    DNA L ;
    this->seq = new char ;
    this->seq = L->seq ;
    c.LoadCodonsFromFile("aminoacids.txt");
    for ( int i = 0 ; i<strlen(bigDNA.seq)-strlen(seq)*3+1 ; i++){
        char* temp = new char [strlen(seq)*3+1] ;
        temp[strlen(seq)*3]=NULL;
        for (int j = 0 ; j < strlen(seq)*3 ; ++j){
            temp[j]=bigDNA.seq[i+j];

        }
        DNA a;
        strcpy(a->seq,temp);
        RNA r(a->ConvertToRNA());
        //r = a.ConvertToRNA();
        Protein p ;
        p = r.ConvertToProtein(c) ;
        if (p== *this){
            cout <<d<<endl;
           l = a;
        }
       strcat(d.seq,l.seq) ;

    }
    return d ;
}
*/
ostream& operator<< (ostream& out ,Protein& p1)
{
 //   out << p1.length << "  " << p1.seq << endl ;
    return  out ;
}
istream& operator>> (istream& in ,Protein & p1)
{
    int type ;
    cout << "HEY!!" << endl ;
    cout << "ENTER THE LENGTH OF THE SEQUENCE:" << endl ;
    in >> p1.length ;
    cout << "ENTER YOUR SEQUENCE PLEASE" << endl;
    in >> p1.seq ;
    if (p1.length != strlen(p1.seq))
    {
        cout <<"^^^^^^"<<"ERROR!!"<<"^^^^^^" << endl ;
        cout <<"PLEASE ENTER SEQUENCE RIGHT:"<< endl ;
        cin >> p1.seq ;
    }
    cout << "enter your type from the types of DNA " << endl ;
    cout <<"{Hormon, Enzyme, TF, Cellular_Function}" << endl ;
    cout << "PLEASE choice between numbers {0 , 1 , 2 , 3}" << endl ;
    in >> type ;
    p1.type=Protein_Type(type);
    if (type == 0)
    {
        cout <<"so your type is" <<" :: "<< "Hormon" << endl ;
    }
    else if (type==1)
    {
        cout <<"so your type is" <<" :: " <<"Enzyme" << endl ;
    }
    else if (type==2)
    {
        cout <<"so your type is" <<" :: "<< "TF" << endl ;
    }
    else if (type==3)
    {
        cout <<"so your type is" <<" :: "<< "Cellular_Function" << endl ;
    }
    else
    {
        cout <<"so your type is" <<" :: "<< "ERROR" << endl ;
    }
    cout << endl ;
    cout << "NEXT" << endl ;
    return in ;

}
char* Protein::operator+(Protein &s1)
{
    char* s3 = new char[strlen(seq)+strlen(s1.seq) + 1] ;
    strcpy(s3 , seq) ;
    strcat(s3 ,s1.seq) ;
    return s3 ;
}
bool Protein::operator==(Protein &s1)
{

    if (this->seq == s1.seq)
    {
       // cout << "TWO SEQUENCES ARE EQUAL:" << endl ;
        return true ;
    }
    else
    {
      //  cout << "TWO SEQUENCES ARE NOT EQUAL" << endl ;
        return false ;
    }
}
bool Protein::operator!=(Protein& s1)
{
   // s1 = new char ;
    if (this->seq != s1.seq)
    {
       // cout << "TWO SEQUENCES ARE NOT EQUAL:" << endl ;
        return true ;
    }
    else
    {
       // cout << "TWO SEQUENCES ARE EQUAL" << endl ;
        return false ;
    }
}
