//
// Created by tjb3 on 2/24/17.
//

#ifndef HTGS_TYPES_HPP
#define HTGS_TYPES_HPP

#include <vector>
#include <unordered_map>
#include <htgs/core/graph/AnyConnector.hpp>
#include <htgs/api/IRule.hpp>
#include <htgs/api/MemoryData.hpp>
#include <map>

/**
 * @namespace the Hybrid Task Graph Scheduler Namespace
 */
namespace htgs {

template<class T, class U>
using IRuleList = std::list<std::shared_ptr<IRule<T, U>>>;

/**
 * @typedef ConnectorMap
 * A mapping between the name of a task and its connector
 */
typedef std::unordered_map<std::string, std::shared_ptr<AnyConnector>> ConnectorMap;

/**
 * @typedef ConnectorPair
 * A pair used for the ConnectorMap
 */
typedef std::pair<std::string, std::shared_ptr<AnyConnector>> ConnectorPair;

/**
 * @typedef ConnectorVector
 * A vector of Connectors.
 */
typedef std::vector<std::shared_ptr<AnyConnector>> ConnectorVector;

/**
 * @typedef ConnectorVectorMap
 * An unordered mapping of string names mapping to a pointer to ConnectorVectors.
 * This data structure is used for execution pipelines and memory edges. Each ITask
 * can only have up to 1 ConnectorVector with a given name. The vector of connectors represents
 * one per execution pipeline.
 */
typedef std::unordered_map<std::string, std::shared_ptr<ConnectorVector>> ConnectorVectorMap;

/**
 * @typedef ConnectorVectorPair
 * Defines a pair to be added to a ConnectorVectorMap.
 */
typedef std::pair<std::string, std::shared_ptr<ConnectorVector>> ConnectorVectorPair;

/**
 * @typedef IRuleMap
 * Defines a mapping between an IRule pointer and the shared pointer of that IRule
 */
typedef std::map<AnyIRule *, std::shared_ptr<AnyIRule>> IRuleMap;

/**
 * @typedef IRulePair
 * Defines a pair to be added to the IRuleMap
 */
typedef std::pair<AnyIRule *, std::shared_ptr<AnyIRule>> IRulePair;

/**
 * @typedef MemAllocMap
 * Defines a mapping between a BaseMemoryAllocator and its shared_ptr
 */
typedef std::map<AnyMemoryAllocator *, std::shared_ptr<AnyMemoryAllocator>> MemAllocMap;

/**
 * @typedef MemAllocPair;
 * Defines a pair to be added to the MemAllocMap
 */
typedef std::pair<AnyMemoryAllocator *, std::shared_ptr<AnyMemoryAllocator>> MemAllocPair;

template<class V>
using m_data_t = std::shared_ptr<MemoryData<V>>;

}
#endif //HTGS_TYPES_HPP
