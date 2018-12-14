#include "CodonTable.h"
#include <bits/stdc++.h>
using namespace std ;
CodonsTable::CodonsTable()
{
}

CodonsTable::~CodonsTable()
{}
void CodonsTable::LoadCodonsFromFile(string codonsFileName)
{
    ifstream codonsfile;
    codonsfile.open(codonsFileName);
    if(codonsfile.fail())
    {
        cout<<"error";
    }
    for(int i=0; !codonsfile.eof(); i++)
    {
        cout<<i<<" ";
        string line;
        getline(codonsfile,line);

        for(int j=0; j<3; j++)
        {

            codons[i].value[j]=line[j];
            cout<<codons[i].value[j];
        }
        codons[i].AminoAcid=line[4];
        cout<<" "<<codons[i].AminoAcid<<endl;
    }
    codonsfile.close();
}


void CodonsTable::setCodon(char * value, char AminoAcid, int index)
{
    codons[index].value[0]=value[0];
    codons[index].value[1]=value[1];
    codons[index].value[2]=value[2];


}

char  CodonsTable:: getAminoAcid(char * value)
{
    int counter;

    for (int i=0; i<64; i++)
    {
        counter=0;
        for(int j=0; j<3; j++)
        {

            if( value[j]==codons[i].value[j])
            {
                counter+=1;
                //cout<<"COUNTER: "<<counter;
            }
        }
        if(counter==3)
        {
            for(int j=0; j<3; j++)
                 cout<<"amino acid: "<<(codons[i].AminoAcid)<<endl;
                return codons[i].AminoAcid;
        }
    }
}
/*
#include "CodonsTable.h"
#include <fstream>


CodonsTable::CodonsTable()
{

}

Codon CodonsTable::getAminoAcid(char * value)
{
    for ( int i = 0; i < 64; i++ )
    {
        bool flag = true;
        char * temp = codons[i].value;
        for ( int j = 0; j < 4; j++ )
        {
            if ( temp[j] != value[j] ) flag = false;
        }
        if ( flag == true )
        {
            return codons[i];
        }
    }
    /*char *arr=new char[4];
    int c=0;
    for(int i=0; i<strlen(value); i++)
    {
        arr[c]=value[i];
        c++;
        if(strlen(arr)==3)
        {
            for(int k = 0; k < 64; k++)
            {
                if(strcmp(arr,codons[k].value)==0)
                {
                    if(codons[k].AminoAcid=='.')
                    {
                        break;
                    }
                    cout << codons[k].value << endl;
                    return codons[k];
                }
                //cout<<codons[k].AminoAcid;
            }
            //arr=new char[50];
            c=0;
        }
    }*/
/*
}

void CodonsTable::setCodon(char * value, char AminoAcid, int index)
{
    for (int i = 0 ; i<3 ; ++i)
    {
        codons[index].value[i]=value[i];
    }
    codons[index].AminoAcid=AminoAcid;

}

void CodonsTable:: LoadCodonsFromFile(string codonsFileName)
{
    /*ifstream file;
    file.open(codonsFileName);
    for(int i=0; i<)
    *//*
    std::ifstream infile;
    infile.open( codonsFileName.c_str() , ios::in );
    string line ;
    char data[4];
    char amino ;
    int i = 0;
    while(infile>>data>>amino)
    {
        if ( amino == '.' ) amino = ' ';
        strcpy(codons[i].value,data);
        codons[i].AminoAcid=amino;
        i++;
    }
     /*if (infile.good()){
                 ///check if file exists
        for (int i=0 ; i<64 ; i++){
            getline(infile,line); /// bia5od kol line
            for (int j = 0 ; j<3 ; j++){
                data[j]=line[j];

            }
        amino=line[4];
        setCodon(data, amino, i);

        }
    }
    else
            cout<<"error";*/
 /*
CodonsTable::~CodonsTable()
{

*/
