//_____________________________________________________________________________

#ifndef BasePlateParameterisation_H
#define BasePlateParameterisation_H 1

#include "globals.hh"
#include "G4VNestedParameterisation.hh"
#include <vector>
#include <math.h> 
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
class G4VPhysicalVolume;
class G4Element;
class G4Material;
class G4MaterialPropertiesTable;

//_______________________________________________________________________________

class BasePlateParameterisation : public G4VNestedParameterisation
{ 
public:  
  BasePlateParameterisation(G4RotationMatrix* r, G4Material* m, G4int n, G4double midrad);
  virtual ~BasePlateParameterisation();
  virtual void ComputeTransformation (const G4int, G4VPhysicalVolume* physVol) const;

  virtual G4Material* ComputeMaterial(G4VPhysicalVolume *currentVol, const G4int, const G4VTouchable *parentTouch);
  G4int GetNumberOfMaterials() const;
  G4Material* GetMaterial(G4int idx) const;
  G4int GetMaterialIndex(const G4int parentCopyNo) const;

private:
	G4RotationMatrix* rot;
  G4Material* mat;
	G4int nBasePlates;
	G4double midradius;
};

//______________________________________________________________________________________________

#endif

