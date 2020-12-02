#ifndef __DNASEQUENCE_H__
#define __DNASEQUENCE_H__

#include <vector>
#include <iostream>
#include <cstring>
#include "invalidDna.h"
#include "outOfRangeDna.h"

using namespace std;

class DnaSequence{
private:
	//char changePair(char dna_chr);
	size_t isSubSeq(DnaSequence & sub_seq,size_t i,int first_call);
	void initChrDna(const char *dna);
	class Nucleotid{
	public:
        operator char();
		Nucleotid();
		Nucleotid(const char dna);
		Nucleotid& operator = (const Nucleotid & dna);
		char m_dna;
	};
	Nucleotid *m_nucleotid;
	size_t m_len;  

public:

	DnaSequence(const char *dna);
    DnaSequence(const std::string dna);
    DnaSequence(const DnaSequence & dna);
	~DnaSequence();

	DnaSequence& operator = (const DnaSequence & dna);
    const char *getDnaStr();
	const DnaSequence::Nucleotid& operator[](size_t index) const ;
	DnaSequence::Nucleotid& operator[](size_t index);
	DnaSequence slice(size_t start,size_t last);
	DnaSequence pairingDna();
	size_t find(DnaSequence & sub_seq);
	size_t count(DnaSequence & sub_seq);
	std::vector <size_t> findAll(DnaSequence & sub_seq);
	std::vector <DnaSequence> findConsensusSequences();
};

bool operator==(DnaSequence & dna1,DnaSequence & dna2);
bool operator!=(DnaSequence & dna1,DnaSequence & dna2);

size_t strLength(DnaSequence & dna);
std::ostream & operator<<(std::ostream & os,DnaSequence & dna);
static bool IsInvalid(const char dna);
DnaSequence readFile(const char * filename);
void writeFile(DnaSequence & dna,const char * file_name);
static char changePair(char dna_chr);

inline DnaSequence::Nucleotid::Nucleotid(){}

inline DnaSequence::Nucleotid::Nucleotid(const char dna):m_dna(dna){
    if(!IsInvalid(m_dna))
        throw InvalidDna();
}

inline DnaSequence::Nucleotid & DnaSequence::Nucleotid::operator =(const Nucleotid & dna)
{
	m_dna=dna.m_dna;
	return *this;
}

inline void DnaSequence::initChrDna(const char *dna){

	m_nucleotid = new Nucleotid[m_len];

	for(size_t i=0;i<m_len;i++)
	{
        try {
            m_nucleotid[i] = Nucleotid(dna[i]);
        }
        catch (InvalidDna &e){
            delete[]m_nucleotid;
            throw;
        }
	}
    m_nucleotid[m_len]='\0';
}

inline DnaSequence::DnaSequence(const char * dna):m_nucleotid(NULL),m_len(strlen(dna)){
	initChrDna(dna);
}

static bool IsInvalid(const char dna){
    if(!(dna=='A'||dna=='C'||dna=='G'||dna=='T'||dna=='\0')){
        return false;
    }
    return true;
}

inline DnaSequence::DnaSequence(const std::string dna):m_nucleotid(NULL),m_len(dna.length())
{
	initChrDna(dna.c_str());
}

inline DnaSequence::DnaSequence(const DnaSequence & dna):m_nucleotid(NULL),m_len(dna.m_len) {
	m_nucleotid = new Nucleotid[m_len];

	for(size_t i=0;i<m_len;i++)
	{
		m_nucleotid[i]=dna.m_nucleotid[i];	
	}
}

inline DnaSequence::~DnaSequence(){
	delete[] m_nucleotid;
}

inline std::ostream & operator<<(std::ostream & os,DnaSequence & dna){
    os<<dna.getDnaStr()<<std::endl;
    return os;
}

inline DnaSequence & DnaSequence::operator = (const DnaSequence & dna)
{
    if (this == &dna)
		return  *this;
	Nucleotid *tmp=m_nucleotid;
	m_nucleotid = new Nucleotid[m_len];
	m_len=dna.m_len;
	for(size_t i=0;i<m_len;i++)
	{
		m_nucleotid[i]=dna.m_nucleotid[i];	
	}
    delete [] tmp;    
    return *this;
}

inline bool operator==(DnaSequence & dna1,DnaSequence & dna2){

	if(strcmp(dna1.getDnaStr(),dna2.getDnaStr())==0)
		return true;
	return false;
}

inline bool operator!=(DnaSequence & dna1,DnaSequence & dna2){
    return !(dna1== dna2);
}

inline const DnaSequence::Nucleotid& DnaSequence::operator[](size_t index)const {

    if (index>m_len)
        throw OutOfRangeDna();
    return m_nucleotid[index];
}

inline DnaSequence::Nucleotid& DnaSequence::operator[](size_t index){

    if (index>m_len)
        throw OutOfRangeDna();
    return m_nucleotid[index];
}

inline size_t strLength(DnaSequence & dna){
    return strlen(dna.getDnaStr());
}

inline const char * DnaSequence::getDnaStr(){
	char *str_dna=new char[m_len+1];

	for(size_t i=0;i<m_len;i++)
	{
		str_dna[i] = m_nucleotid[i].m_dna; 	
	}
    str_dna[m_len] = '\0';
    return str_dna;
}

inline DnaSequence::Nucleotid::operator char(){
	return m_dna;
}

inline DnaSequence DnaSequence::slice(size_t start,size_t last){
    if (last<start)
        throw OutOfRangeDna();

	if (last>m_len)
        throw OutOfRangeDna();

	std::string slice_dna ="";
	for(size_t i=start; i<last;i++)
	{
		slice_dna+=m_nucleotid[i].m_dna;
	}
	return DnaSequence((std::string)slice_dna);
}

static char changePair(char dna_chr)
{
	if(dna_chr=='A')
		return 'T';
	if(dna_chr=='T')
		return 'A';
	if(dna_chr=='C')
		return 'G';
	return 'C';
}

inline DnaSequence DnaSequence::pairingDna(){
	const char * keep_dna_str=getDnaStr();
	(std::string)keep_dna_str;
	std::string dna_str;
	for(size_t i=0; i<=m_len;i++)
	{
		dna_str+=changePair(keep_dna_str[m_len-i]);
	}
	return DnaSequence(dna_str);
}	

inline size_t DnaSequence::find(DnaSequence & sub_seq)
{
	for(size_t i=0; i <= m_len-sub_seq.m_len; i++)
	{
		
		for(size_t j=0; j<=sub_seq.m_len;j++)
		{

			if(sub_seq.m_nucleotid[j].m_dna == m_nucleotid[i].m_dna)
			{
				DnaSequence slice_seq=slice(i,i+sub_seq.m_len);

				if(strcmp(slice_seq.getDnaStr(),sub_seq.getDnaStr())==0)
				{
					return i;
				}
			}
		}
	}
	std::cout<<"Can't find this subsequence"<<std::endl;
	return SIZE_MAX;
}


inline size_t DnaSequence::isSubSeq(DnaSequence & sub_seq,size_t i,int first_call)
{
	if(first_call==1&&i==0)
	    i+=1;
	for(; i<=m_len-sub_seq.m_len;i++)
	{
		for(size_t j=0; j<=sub_seq.m_len;j++)
		{

			if(sub_seq.m_nucleotid[j].m_dna==m_nucleotid[i].m_dna)
			{
				DnaSequence slice_seq=slice(i,i+sub_seq.m_len);

				if(strcmp(slice_seq.getDnaStr(),sub_seq.getDnaStr())==0)
				{
					return i;
				}
			}
		}
	}
	return m_len+1;
}

inline size_t DnaSequence::count(DnaSequence & sub_seq)
{
	size_t count_sub_seq =0;
	size_t i=this->isSubSeq(sub_seq,0,0);
	while(i!=(m_len+1))
	{ 
		count_sub_seq+=1;
		i=this->isSubSeq(sub_seq,i+1,1);
	}
	return count_sub_seq;
}


inline std::vector <size_t> DnaSequence::findAll(DnaSequence &sub_seq)
{
	std::vector <size_t> find_all_sub_seq;
	size_t i = this->isSubSeq(sub_seq,0,0);
	while(i != (m_len+1))
	{
		find_all_sub_seq.push_back(i);
		i = this->isSubSeq(sub_seq,i + 1,1);
	}
	return find_all_sub_seq;
}

/*inline std::vector <DnaSequence> DnaSequence::findConsensusSequences()
{
	std::vector <DnaSequence> find_consensus_seq;
    DnaSequence first="ATG";
	std::vector <size_t> find_all_ATC=findAll(first);
	std::vector <size_t> find_all_end;
		
	for(size_t i=0; i<=m_len-3;i++)
	{
		
		if(m_nucleotid[i].m_dna=='T')
		{
			DnaSequence slice_seq=slice(i,i+3);
			const char * slice_seq_chr=slice_seq.getDnaStr();
			if(strcmp(slice_seq_chr,DnaSequence("TAG").getDnaStr())==0||strcmp(slice_seq_chr,DnaSequence("TAA").getDnaStr())==0||strcmp(DnaSequence("TGA").getDnaStr(),slice_seq_chr)==0)
			{
				find_all_end.push_back(i);
			}
		}
	}

    for (size_t i=0;i<find_all_ATC.size();i++) {

        for (size_t k = 0; k < find_all_end.size(); k++) {

            if ((find_all_ATC[i] % 3 == find_all_end[k] % 3) && (find_all_ATC[i] < find_all_end[k])) {
                find_consensus_seq.push_back(slice(i, k));
            }
        }
    }
	return find_consensus_seq;
}*/

#endif
