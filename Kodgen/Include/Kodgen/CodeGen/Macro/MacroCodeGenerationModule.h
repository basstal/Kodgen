/**
*	Copyright (c) 2021 Julien SOYSOUVANH - All Rights Reserved
*
*	This file is part of the Kodgen library project which is released under the MIT License.
*	See the README.md file for full license details.
*/

#pragma once

#include "Kodgen/CodeGen/CodeGenerationModule.h"
#include "Kodgen/Misc/ECodeGenLocation.h"

namespace kodgen
{
	/**
	*	Module used with MacroFileGenerationUnit class.
	*/
	class MacroCodeGenerationModule : public CodeGenerationModule
	{
		public:
			struct Data : public CodeGenerationData
			{
				ECodeGenLocation generationLocation;
			};

			virtual bool generateCode(EntityInfo const&		entity,
									  CodeGenerationData&	data,
									  std::string&			out_errorMessage) const noexcept override;
	};
}