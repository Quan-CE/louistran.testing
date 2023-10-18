#include "setFunctions.h"
#include "set.h"
#include "set.cpp"

using namespace std;
// Returns a set that is the Union of the two sets s1 and s2
Set<char> setUnion(const Set<char>& s1, const Set<char>& s2)
{
	Set<char> result;
	for(int i=0; i<s1.cardinality(); i++) {
		result.insertElement(s1[i]);
	}
	for(int i=0; i<s2.cardinality(); i++) {
		result.insertElement(s2[i]);
	}
	return result;
}

// Returns a set that is the intersection of the two sets s1 and s2
Set<char> setIntersection(const Set<char>& s1, const Set<char>& s2)
{
	Set<char> result;
	for(int i=0; i<s1.cardinality(); i++) {
		if(s2.isElement(s1[i]) == true) result.insertElement(s1[i]);
	}
	return result;
}

// Returns a set that is the s1 - s2
Set<char> setDiff(const Set<char>& s1, const Set<char>& s2)
{
	Set<char> result;
	for(int i=0; i<s1.cardinality(); i++) {
		if(s2.isElement(s1[i]) == false) result.insertElement(s1[i]);
	}
	return result;
}

// Returns a set that is the symetric difference of the two sets s1 and s2
Set<char> setSymDiff(const Set<char>& s1, const Set<char>& s2)
{
	Set<char> result;
	for(int i=0; i<s1.cardinality(); i++) {
		if(s2.isElement(s1[i]) == false) result.insertElement(s1[i]);
	}
	for(int i=0; i<s2.cardinality(); i++) {
		if(s1.isElement(s2[i]) == false) result.insertElement(s2[i]);
	}
	return result;
}

// Returns true if s1 is a subset of s2
bool isSubSet(const Set<char>& s1, const Set<char>& s2)
{
	if (s1.cardinality() > s2.cardinality()) return false;
	else
	{
		for(int i=0; i<s1.cardinality(); i++) {
			if(s2.isElement(s1[i]) == false) return false;
			else continue;
		}
	}
	return true;
}

// Returns true if s1 is a proper subset of s2
bool isProperSubSet(const Set<char>& s1, const Set<char>& s2)
{
	if (s1.cardinality() >= s2.cardinality()) return false;
	else {	
		for(int i=0; i<s1.cardinality(); i++) {
			if(s2.isElement(s1[i]) == false) return false;
			else continue;
		}
	}
	return true;
}

// Returns the Power Set of set s as a set of sets
Set<Set<char>> PowerSet(const Set<char>& s)
{
	Set<Set<char>> result;
	Set<char> check;
	result.insertElement(check);
	return result;
}

// Returns true if the sets in p make up a Partition of set s
bool isPartition(const Set<Set<char>>& p, const Set<char>& s)
{
	int check[256]{};
	for(int i=0; i<p.cardinality(); i++) {
		for(int j=0; j<p[0].cardinality(); j++) {
			if(s.isElement(p[i][j])) check[p[i][j]] += 1;
		}
	}
	for(int i=0; i<256; i++) {
		if(check[i] > 1) return false;
	}
	return true;
}