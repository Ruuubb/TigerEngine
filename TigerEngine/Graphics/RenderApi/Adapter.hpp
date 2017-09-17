#pragma once

#include <string>

namespace te
{
	namespace gr
	{
		class Adapter
		{
		private:
			std::string m_Description;
			size_t m_VideoMemory;
			size_t m_SystemMemory;
			size_t m_SharedMemory;
			uint32_t m_VendorID;
			uint32_t m_DeviceID;
			bool m_IsRemote;
			bool m_IsSupportingApi;

		public:			
			virtual ~Adapter() = 0 {};

			std::string& GetDescription();
			size_t GetVideoMemory();
			size_t GetSystemMemory();
			size_t GetSharedMemory();
			uint32_t GetVendorID();
			uint32_t GetDeviceID();
			bool GetIsRemote();

		protected:
			Adapter(std::string Desc, size_t VideoMemory, size_t SystemMemory, size_t SharedMemory, uint32_t VendorID, uint32_t DeviceID, bool Remote, bool SupportsApi);

		};
	}
}