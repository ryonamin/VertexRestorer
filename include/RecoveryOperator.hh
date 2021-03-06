#ifndef RecoveryOperator_hh
#define RecoveryOperator_hh 1
#include <iostream>
#include <string>
#include <vector>

#include "MathOperator.hh"
#include "MyReconstructedParticle.hh"
#include "TrackOperator.hh"
#include "marlin/VerbosityLevels.h"

#include <EVENT/LCRelation.h>
#include <IMPL/LCRelationImpl.h>
#include <EVENT/Vertex.h>
#include <EVENT/Track.h>
#include <IMPL/VertexImpl.h>
#include <EVENT/ReconstructedParticle.h>
#include <IMPL/ReconstructedParticleImpl.h>
#include <EVENT/LCCollection.h>
#include <UTIL/LCRelationNavigator.h>
namespace TTbarAnalysis
{
	class RecoveryOperator 
	{
		public:
		//
		//	Constants
		//
	
		//
		//	Constructors
		//
	  RecoveryOperator (EVENT::Vertex * vertex, EVENT::LCCollection *pfos, float bfield);
			virtual ~RecoveryOperator () {};
			std::vector< EVENT::ReconstructedParticle * > * getVertexParticles(EVENT::LCCollection * secvtx, std::vector< EVENT::Vertex * > * tagged);
			std::vector< EVENT::ReconstructedParticle * > getTrackParticles(EVENT::LCCollection * secvtx, std::vector< EVENT::ReconstructedParticle * > * particles = NULL);
			std::vector< EVENT::ReconstructedParticle * > getPFOParticles();
			bool IsMinimalAngle(EVENT::ReconstructedParticle * candidate, EVENT::Vertex * chosen, std::vector< EVENT::Vertex * > * vertices);
			
			std::vector< EVENT::Vertex * > __CheatRecoverJetVertices(EVENT::LCCollection * jetcol, EVENT::LCCollection * jetrelcol, EVENT::LCCollection * secvtx,EVENT::LCCollection * damagedcol = NULL, EVENT::LCCollection * newjetrelcol = NULL);
			std::vector< EVENT::Vertex * > RecoverJetVertices(EVENT::LCCollection * jetcol, EVENT::LCCollection * jetrelcol, EVENT::LCCollection * secvtx,EVENT::LCCollection * damagedcol = NULL, EVENT::LCCollection * newjetrelcol = NULL);
			std::vector< EVENT::Vertex * > RecoverBuildVertices(EVENT::LCCollection * secvtx,EVENT::LCCollection * damagedcol = NULL);
			std::vector< EVENT::ReconstructedParticle * > AddParticles(const std::vector< EVENT::ReconstructedParticle * > & pri, EVENT::Vertex * sec, const std::vector< EVENT::ReconstructedParticle * > * toCompare = NULL, std::vector< EVENT::Vertex * > * allVtx = NULL);
			bool TakeParticle(EVENT::ReconstructedParticle * primary, const EVENT::Vertex * vertex);
			
			EVENT::Vertex * CreateRecoveredVertex(std::vector< EVENT::ReconstructedParticle * > & newtracks, EVENT::Vertex * oldvertex, bool add = true);
			EVENT::LCRelation * CreateNewRelation(EVENT::Vertex * newvertex, EVENT::ReconstructedParticle * oldjet);
			
			bool IsDublicate(const EVENT::ReconstructedParticle * particle, const std::vector< EVENT::ReconstructedParticle * > & data);
			bool CompareParticles(const EVENT::ReconstructedParticle * particle1, const EVENT::ReconstructedParticle * particle2);
			//bool IsDublicate(MyReconstructedParticle * particle, std::vector< MyReconstructedParticle * > & data);
			float GetError(const EVENT::ReconstructedParticle * particle);
			std::vector< float > ParametrizeVertex(const EVENT::Vertex * sec);
			std::vector< EVENT::Vertex * > RefineJetVertices(std::vector< EVENT::Vertex * > & oldvtx);//EVENT::ReconstructedParticle * oldjet, EVENT::LCCollection * jetrelcol);
			void PrintParticle(EVENT::ReconstructedParticle * particle);
			int GetStatistics();
		//
		//	Methods
		//
			float getHadronMomentum(std::vector< EVENT::LCObject * > & objs);	
		private:
		//
		//	Data
		//
			TrackOperator myTrackOperator;
			EVENT::Vertex * myPrimary;
			float _aParameter;
			float _bParameter;
	  float _Bfield;
			EVENT::LCCollection * myPFOs;
			int myTotalTracksCounter;
		//
		//	Private methods
		//
	};
}
#endif
