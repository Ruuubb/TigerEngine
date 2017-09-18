#pragma once

namespace te
{
	namespace gr
	{
		enum class QueueType
		{
			General,
			Compute,
			Copy
		};

		enum class QueuePriority
		{
			Normal,
			High
		};

		struct QueueDesc
		{
			QueueType Type;
			QueuePriority Priority;
		};
	}
}