#include "Adapter.hpp"

namespace te
{
	namespace gr
	{
		Adapter::Adapter(std::string Desc, size_t VideoMemory, size_t SystemMemory, size_t SharedMemory, uint32_t VendorID, uint32_t DeviceID, bool Remote) :
			m_Description(Desc),
			m_VideoMemory(VideoMemory),
			m_SystemMemory(SystemMemory),
			m_SharedMemory(SharedMemory),
			m_VendorID(m_VendorID),
			m_DeviceID(DeviceID),
			m_IsRemote(Remote)
		{

		}

		std::string& Adapter::GetDescription() 
		{
			return m_Description;
		}

		size_t Adapter::GetVideoMemory() 
		{
			return m_VideoMemory;
		}

		size_t Adapter::GetSystemMemory()
		{
			return m_SystemMemory;
		}

		size_t Adapter::GetSharedMemory()
		{
			return m_SharedMemory;
		}

		uint32_t Adapter::GetVendorID()
		{
			return m_VendorID;
		}

		uint32_t Adapter::GetDeviceID()
		{
			return m_DeviceID;
		}

		bool Adapter::GetIsRemote()
		{
			return m_IsRemote;
		}
	}
}