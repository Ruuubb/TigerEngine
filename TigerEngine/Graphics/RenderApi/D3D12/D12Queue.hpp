#pragma once

#include <d3d12.h>
#include <atlbase.h>

#include "../Queue.hpp"

namespace te 
{
	namespace gr
	{
		namespace d12
		{
			class D12Device;

			class D12Queue : public Queue
			{
			private:
				CComPtr<ID3D12CommandQueue> m_Queue;

			public:
				D12Queue();
				~D12Queue();

				Result Initialize(D12Device* Dev, QueueDesc& Desc);

				Result Submit() override;
				Result Signal() override;
			
				
			};
		}
	}
}
