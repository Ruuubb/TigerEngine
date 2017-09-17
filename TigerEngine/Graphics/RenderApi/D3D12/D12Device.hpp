#pragma once

#include "../Device.hpp"

#include <d3d12.h>
#include <atlbase.h>

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

				Result Initialize() override;
				Result Shutdown() override;

				Result CreateVertexBuffer() override;
				Result CreateIndexBuffer() override;
				Result CreateConstantBuffer()override;
				Result CreateCommandPool() override;
				Result CreateCommandBuffer() override;
				Result CreateQueue() override;
				Result CreateFence() override;
				Result CreateSwapchain() override;
				Result CreateRenderPass() override;
				Result CreatePipeline() override;
				Result CreateFrameBuffer() override;
				Result CreateImage() override;
				Result CreateImageView() override;

			private:
			};
		}
	}
}