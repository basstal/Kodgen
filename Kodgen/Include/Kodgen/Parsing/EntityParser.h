/**
*	Copyright (c) 2020 Julien SOYSOUVANH - All Rights Reserved
*
*	This file is part of the Kodgen library project which is released under the MIT License.
*	See the LICENSE.md file for full license details.
*/

#pragma once

#include <stack>
#include <cassert>

#include <clang-c/Index.h>

#include "Kodgen/Parsing/ParsingContext.h"
#include "Kodgen/Parsing/ParsingSettings.h"
#include "Kodgen/InfoStructures/EntityInfo.h"
#include "Kodgen/Misc/FundamentalTypes.h"

namespace kodgen
{
	class EntityParser
	{
		protected:
			/** Stack of contexts of this parser. */
			std::stack<ParsingContext>	contextsStack;

			/**
			*	@brief	Update the shouldParseAllNested boolean in the current context.
			*	
			*	@param parsingEntity The currently parsing entity.
			*/
			void	updateShouldParseAllNested(EntityInfo const& parsingEntity)		noexcept;

			/**
			*	@brief Check if the current entity (stored in the current context) should be parsed.
			*	
			*	@return true if it should be parsed regardless whether it is annotated or not, else false.
			*/
			inline bool						shouldParseCurrentEntity()		const	noexcept;

			/**
			*	@brief Pop the most recent context from the contexts stack.
			*/
			inline void						popContext()							noexcept;

			/**
			*	@brief Get the current in-use context.
			*
			*	@return The current context.
			*/
			inline ParsingContext&			getContext()							noexcept;

			/**
			*	@brief Get the current in-use context.
			*
			*	@return The current context.
			*/
			inline ParsingContext const&	getContext()					const	noexcept;
	};

	#include "Kodgen/Parsing/EntityParser.inl"
}