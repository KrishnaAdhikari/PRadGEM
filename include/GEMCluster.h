/*******************************************************************************
 *  GEMCluster                                                                  *
 *  GEM Module Class                                                            *
 *  Author: Kondo GNANVO 18/08/2010                                             *
 *******************************************************************************/
#ifndef GEMCLUSTER_H
#define GEMCLUSTER_H

#include <TObject.h>
#include <TObjArray.h>

class GEMHit;

class GEMCluster: public TObject
{
public:
    GEMCluster(Int_t minClusterSize, 
               Int_t maxClusterSize, 
	       TString isMaximumOrTotalCharges);
    ~GEMCluster();
    Bool_t IsSortable() const {
	return kTRUE;
    }
    TObjArray* GetArrayOfHits() {
	return fArrayOfHits;
    }
    GEMHit * GetHit(Int_t i) { 
	TObjArray &temp = * fArrayOfHits ;
	return (GEMHit *)temp[i];
    }
    void SetMinClusterSize(Int_t min) {
	fMinClusterSize = min ; 
    }
    void SetMaxClusterSize(Int_t max) {
	fMaxClusterSize = max ; 
    }
    void AddHit(GEMHit * h);
    int Compare(const TObject *obj) const ; 
    Int_t & GetNbOfHits(){ 
	return fNbOfHits ;  
    }
    TString GetPlane(){
	return fPlane;
    }
    void SetPlane(TString planename){
	fPlane = planename;
    }
    Int_t GetNbAPVsFromPlane(){
	return fNbAPVsOnPlane;
    }
    void SetNbAPVsFromPlane(Int_t nb){
	fNbAPVsOnPlane = nb;
    }
    Int_t GetAPVIndexOnPlane() {
	return fapvIndexOnPlane;
    }
    void SetAPVIndexOnPlane(Int_t nb) {
	fapvIndexOnPlane = nb;
    }
    Float_t GetPlaneSize() {
	return fPlaneSize;
    }
    void SetPlaneSize(Float_t planesize) {
	fPlaneSize = planesize;
    }

    Float_t & GetClusterPosition(){
	return fposition;
    }
    Float_t & GetClusterCentralStrip() {
	return fclusterCentralStrip;
    }
    void Timing() ;
    Int_t GetClusterTimeBin()  ;
    Int_t GetClusterPeakTimeBin() {
	return fClusterPeakTimeBin ;
    }
    Float_t GetClusterADCs() ;
    void SetClusterADCs(Float_t adc) {
	fClusterSumADCs = adc;
    }
    //void Dump() ;
    void ClearArrayOfHits();
    Bool_t IsGoodCluster() ;
    void ClusterCentralStrip();
    void ClusterPositionPulseHeghtWeight() ;
    std::vector< Float_t > GetClusterTimeBinADCs () {
	return fClusterTimeBinADCs; 
    }
    void ComputeClusterPosition() ;

private:
    Int_t fNbOfHits;
    TObjArray * fArrayOfHits;  // APV hits table
    Int_t fClusterPeakTimeBin, fClusterTimeBin;
    Float_t fClusterPeakADCs, fClusterTimeBinADC, fClusterSumADCs, fposition, fclusterCentralStrip, fstrip, fPlaneSize;
    Int_t fapvID, fStripNo, fAbsoluteStripNo, fapvIndexOnPlane, fNbAPVsOnPlane, fMinClusterSize, fMaxClusterSize;   
    TString fIsClusterMaxOrSumADCs, fPlane;
    Bool_t fIsGoodCluster ;

    std::vector< Float_t > fClusterTimeBinADCs ;
}; 
#endif
