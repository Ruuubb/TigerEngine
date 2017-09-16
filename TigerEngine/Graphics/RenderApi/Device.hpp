#pragma once

#include "Result.hpp"

namespace te
{
	namespace gr
	{
		class Device
		{
		public:
			Device(const Device& Other) = delete; // copy constructor
			Device(Device&& Other) = delete; // move constructor
			Device& operator=(const Device& Other) = delete; // copy assignment
			Device& operator=(Device&& Other) = delete; // move assignment

			virtual Result Initialize() = 0;
			virtual Result Shutdown() = 0;

			virtual Result CreateVertexBuffer() = 0;
			virtual Result CreateIndexBuffer() = 0;
			virtual Result CreateConstantBuffer() = 0;
			virtual Result CreateCommandPool() = 0;
			virtual Result CreateCommandBuffer() = 0;
			virtual Result CreateQueue() = 0;
			virtual Result CreateFence() = 0;
			virtual Result CreateSwapchain() = 0;
			virtual Result CreateRenderPass() = 0;
			virtual Result CreatePipeline() = 0;
			virtual Result CreateFrameBuffer() = 0;
			virtual Result CreateImage() = 0;
			virtual Result CreateImageView() = 0;		

		protected:
			Device() {};

		};
	}
}