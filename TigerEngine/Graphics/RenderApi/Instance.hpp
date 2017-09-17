#pragma once

#include <vector>
#include <memory>

#include "Result.hpp"


namespace te
{
	namespace gr
	{
		class Adapter;
		class Device;

		class Instance
		{
		public:
			virtual Result EnumerateAdapters(std::vector<std::unique_ptr<Adapter>>& Adapters) = 0;
			virtual Result CreateDevice(std::unique_ptr<Adapter> UsedAdapter, Device** CreatedDevice) = 0;

			Instance(const Instance& Other) = delete; // copy constructor
			Instance(Instance&& Other) = delete; // move constructor
			Instance& operator=(const Instance& Other) = delete; // copy assignment
			Instance& operator=(Instance&& Other) = delete; // move assignment

		protected:
			Instance() {};
			virtual ~Instance() = 0 {};
		};
	}
}