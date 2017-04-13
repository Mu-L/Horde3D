// *************************************************************************************************
//
// Horde3D
//   Next-Generation Graphics Engine
// --------------------------------------
// Copyright (C) 2006-2016 Nicolas Schulz and Horde3D team
//
// This software is distributed under the terms of the Eclipse Public License v1.0.
// A copy of the license may be obtained at: http://www.eclipse.org/legal/epl-v10.html
//
// *************************************************************************************************

#ifndef _egComputeNode_H_
#define _egComputeNode_H_

#include "egScene.h"
#include "egMaterial.h"
#include "egComputeBuffer.h"

namespace Horde3D {

// =================================================================================================
// Compute Node
// =================================================================================================
struct ComputeNodeParams
{
	enum List
	{
		MatResI = 800,
		CompBufResI,
		AABBMinF,
		AABBMaxF
	};
};

struct ComputeNodeTpl : public SceneNodeTpl
{
	PMaterialResource		matRes;
	PComputeBufferResource  compBufRes;

	ComputeNodeTpl( const std::string &name, ComputeBufferResource *computeBufferRes, MaterialResource *materialRes ) :
		SceneNodeTpl( SceneNodeTypes::Compute, name ), compBufRes( computeBufferRes ), matRes( materialRes )
	{
	}

};

class ComputeNode : public SceneNode
{
public:

	static SceneNodeTpl *parsingFunc( std::map< std::string, std::string > &attribs );
	static SceneNode *factoryFunc( const SceneNodeTpl &nodeTpl );

	void onPostUpdate();

	int getParamI( int param ) const;
	void setParamI( int param, int value );
	float getParamF( int param, int compIdx ) const;
	void setParamF( int param, int compIdx, float value );

	friend class Renderer;
	friend class SceneManager;

protected:

	ComputeNode( const ComputeNodeTpl &computeTpl );
	~ComputeNode();

protected:

	BoundingBox				_localBBox;

	PMaterialResource		_materialRes;
	PComputeBufferResource	_compBufferRes;

};

} // namespace

#endif // _egComputeNode_H