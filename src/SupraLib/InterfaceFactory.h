// ================================================================================================
// 
// If not explicitly stated: Copyright (C) 2016, all rights reserved,
//      Rüdiger Göbl 
//		Email r.goebl@tum.de
//      Chair for Computer Aided Medical Procedures
//      Technische Universität München
//      Boltzmannstr. 3, 85748 Garching b. München, Germany
// 
// ================================================================================================

#ifndef __INTERFACEFACTORY_H__
#define __INTERFACEFACTORY_H__

#include "AbstractNode.h"
#include "AbstractInput.h"
#include "AbstractOutput.h"

#include <tbb/flow_graph.h>

#include <functional>
#include <memory>

namespace supra
{
	class InterfaceFactory {
	public:
		static std::shared_ptr<tbb::flow::graph> createGraph();
		static std::shared_ptr<AbstractInput> createInputDevice(std::shared_ptr<tbb::flow::graph> pG, const std::string& nodeID, std::string deviceType, size_t numPorts);
		static std::shared_ptr<AbstractOutput> createOutputDevice(std::shared_ptr<tbb::flow::graph> pG, const std::string & nodeID, std::string deviceType, bool queueing);
		static std::shared_ptr<AbstractNode> createNode(std::shared_ptr<tbb::flow::graph> pG, const std::string & nodeID, std::string nodeType, bool queueing);
		static std::vector<std::string> getNodeTypes();

	private:
		typedef std::function<std::shared_ptr<AbstractNode>(tbb::flow::graph&, std::string, bool)> nodeCreationFunctionType;

		static std::map<std::string, nodeCreationFunctionType> m_nodeCreators;
	};
}

#endif //!__INTERFACEFACTORY_H__
