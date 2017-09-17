#pragma once

#include <dxgi1_4.h>
#include <d3d12.h>
#include <d3d12sdklayers.h>
#include <atlbase.h>

#include "D12Adapter.hpp"
#include "../Instance.hpp"

namespace te
{
	namespace gr
	{
		namespace d12
		{
			class D12Instance : public te::gr::Instance
			{
			private:
				CComPtr<IDXGIFactory2> m_DxFactory;
				CComPtr<ID3D12Debug> m_DebugController;

			public:
				D12Instance();
				~D12Instance() override;

				Result EnumerateAdapters(std::vector<std::unique_ptr<Adapter>>& Adapters) override;
				Result CreateDevice(std::unique_ptr<Adapter> UsedAdapter, Device** CreatedDevice) override;


			private:
			};
		}
	}
}