#pragma once

#include <memory>

#include "Result.hpp"
//#include "Adapter.hpp"

namespace te
{
	namespace gr
	{
		class Adapter;
		class CommandBuffer;
		class CommandPool;
		class ConstantBuffer;
		class Fence;
		class FrameBuffer;
		class Image;
		class ImageView;
		class IndexBuffer;
		class Pipeline;
		class Queue;
		class RenderPass;
		class Swapchain;
		class VertexBuffer;

		struct QueueDesc;
		struct SwapchainDesc;

		class Device
		{
		protected:
			std::unique_ptr<Adapter> m_Adapter;

		public:
			virtual ~Device() = 0 {};

			Device(const Device& Other) = delete; // copy constructor
			Device(Device&& Other) = delete; // move constructor
			Device& operator=(const Device& Other) = delete; // copy assignment
			Device& operator=(Device&& Other) = delete; // move assignment

			virtual Result Initialize() = 0;
			virtual Result Shutdown() = 0;

			virtual Result CreateVertexBuffer(VertexBuffer** CreatedVertexBuffer) = 0;
			virtual Result CreateIndexBuffer(IndexBuffer** CreatedIndexBuffer) = 0;
			virtual Result CreateConstantBuffer(ConstantBuffer** CreatedConstantBuffer) = 0;
			virtual Result CreateCommandPool(CommandPool** CreatedCommandPool) = 0;
			virtual Result CreateCommandBuffer(CommandBuffer** CreatedCommandBuffer) = 0;
			virtual Result CreateQueue(QueueDesc& Desc, Queue** CreatedQueue) = 0;
			virtual Result CreateFence(Fence** CreatedFence) = 0;
			virtual Result CreateSwapchain(SwapchainDesc& Desc, Swapchain** CreatedSwapchain) = 0;
			virtual Result CreateRenderPass(RenderPass** RenderPass) = 0;
			virtual Result CreatePipeline(Pipeline** CreatedPipeline) = 0;
			virtual Result CreateFrameBuffer(FrameBuffer** CreatedFrameBuffer) = 0;
			virtual Result CreateImage(Image** CreatedImage) = 0;
			virtual Result CreateImageView(ImageView** CreatedImageView) = 0;

		protected:
			Device(std::unique_ptr<Adapter> UsedAdapter);
			

		};
	}
}