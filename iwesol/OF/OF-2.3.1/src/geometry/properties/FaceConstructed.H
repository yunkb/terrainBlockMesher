/*---------------------------------------------------------------------------*\
                               |
  _____        _______ ____    | IWESOL: IWES Open Library
 |_ _\ \      / / ____/ ___|   |
  | | \ \ /\ / /|  _| \___ \   | Copyright: Fraunhofer Institute for Wind
  | |  \ V  V / | |___ ___) |  | Energy and Energy System Technology IWES
 |___|  \_/\_/  |_____|____/   |
                               | http://www.iwes.fraunhofer.de
                               |
-------------------------------------------------------------------------------
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright  held by original author
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of IWESOL and it is based on OpenFOAM.

    IWESOL and OpenFOAM are free software: you can redistribute them and/or modify
    them under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    IWESOL and OpenFOAM are distributed in the hope that they will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Class
    Foam::oldev::FaceConstructed

Description

SourceFiles
    FaceConstructedI.H
    FaceConstructed.C
    FaceConstructedIO.C

\*---------------------------------------------------------------------------*/

#ifndef FaceConstructed_H
#define FaceConstructed_H

#include "primitiveMesh.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace oldev
{

/*---------------------------------------------------------------------------*\
                         Class FaceConstructed Declaration
\*---------------------------------------------------------------------------*/

class FaceConstructed
{
    // Private data

    	/// the resolution
    	scalar resolution_;


public:

    // Constructors

    	/// Constructor
    	FaceConstructed
    	(
    			const double & resolution = 0.001
    	);

    	/// Constructor
    	FaceConstructed
    	(
    			const dictionary & dict
    	);


    /// Destructor
    virtual ~FaceConstructed();


    // Member Functions

        // Access

    	/// FaceConstructed: return faces
    	virtual const faceList & faces() const = 0;

    	/// FaceConstructed: return points
    	virtual const pointField & points() const = 0;

    	/// FaceConstructed: return start face in face list
    	virtual label startFaceIndex() const = 0;

    	/// FaceConstructed: return number of faces
    	virtual label nFaces() const = 0;

    	/// FaceConstructed: return face centres
    	virtual const pointField & Cf() const = 0;

    	/// FaceConstructed: return face area vectors
    	virtual const vectorField & Sf() const = 0;

    	/// returns the resolution
    	inline const scalar & resolution() const { return resolution_; }

    	/// Returns true if the point lies inside/beside
    	bool isInside(const point & p) const;

    	/// Returns true if the point lies on the boundary
    	bool isBoundary(const point & p) const;

    	/// Returns true if the point lies inside/beside
    	bool isNotOutside(const point & p) const;


        // Write

    	/// exports to STL
    	void writeSTL(const fileName & file, bool binary = false) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace oldev

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //



// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
