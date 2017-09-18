#pragma once

#include <d3d12.h>
#include <atlbase.h>

#include "../Device.hpp"



namespace te
{
	namespace gr
	{
	
		namespace d12
		{
			class D12Device : public te::gr::Device
			{
			private:
				CComPtr<ID3D12Device> m_Device;

			public:
				D12Device(std::unique_ptr<Adapter> UsedAdapter);
				~D12Device();

				Result Initialize() override;
				Result Shutdown() override;

				Result CreateVertexBuffer(VertexBuffer** CreatedVertexBuffer) override;
				Result CreateIndexBuffer(IndexBuffer** CreatedIndexBuffer) override;
				Result CreateConstantBuffer(ConstantBuffer** CreatedConstantBuffer) override;
				Result CreateCommandPool(CommandPool** CreatedCommandPool) override;
				Result CreateCommandBuffer(CommandBuffer** CreatedCommandBuffer) override;
				Result CreateQueue(QueueDesc& Desc, Queue** CreatedQueue) override;
				Result CreateFence(Fence** CreatedFence) override;
				Result CreateSwapchain(SwapchainDesc& Desc, Swapchain** CreatedSwapchain) override;
				Result CreateRenderPass(RenderPass** RenderPass) override;
				Result CreatePipeline(Pipeline** CreatedPipeline) override;
				Result CreateFrameBuffer(FrameBuffer** CreatedFrameBuffer) override;
				Result CreateImage(Image** CreatedImage) override;
				Result CreateImageView(ImageView** CreatedImageView) override;

				ID3D12Device* GetDevice() const;
				Device* Get() { return this; }
			private:
			};
		}
	}
}