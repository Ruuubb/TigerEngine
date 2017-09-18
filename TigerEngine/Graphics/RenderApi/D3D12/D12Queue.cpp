#include "D12Queue.hpp"
#include "D12Device.hpp"

#include "../Adapter.hpp"

#include "../InitStructs/QueueDesc.hpp"

namespace te
{
	namespace gr
	{
		namespace d12
		{
			D12Queue::D12Queue()
			{

			}

			D12Queue::~D12Queue()
			{

			}

			Result D12Queue::Initialize(D12Device* Dev, QueueDesc& Desc)
			{
				D3D12_COMMAND_LIST_TYPE Type;
				int Priority;

				switch (Desc.Type)
				{
				case QueueType::Compute:	Type = D3D12_COMMAND_LIST_TYPE_COMPUTE;
				case QueueType::Copy:		Type = D3D12_COMMAND_LIST_TYPE_COPY;
				case QueueType::General:	Type = D3D12_COMMAND_LIST_TYPE_DIRECT;
				}			

				if (Desc.Priority == QueuePriority::Normal)
					Priority = 0;
				else
					Priority = 100; // high
				//TODO there is also globa ??

				D3D12_COMMAND_QUEUE_DESC desc;
				ZeroMemory(&desc, sizeof(desc));
				desc.Type = Type;
				desc.Priority = Priority;
				desc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE; //TODO anything here ??
				desc.NodeMask = 0;

				Dev->GetDevice()->CreateCommandQueue(&desc, IID_PPV_ARGS(&m_Queue));

				return Result();
			}

			Result D12Queue::Submit()
			{
				return Result();
			}

			Result D12Queue::Signal()
			{
				return Result();
			}

		}
	}
}