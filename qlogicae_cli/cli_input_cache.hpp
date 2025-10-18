#pragma once

#include "cli_transformer.hpp"

namespace QLogicaeCLI
{
	template <typename Type>
	class CLIInputCache
	{
	public:
		CLIInputCache();

		~CLIInputCache();

		CLIInputCache(
			const CLIInputCache&
		) = delete;

		CLIInputCache(
			CLIInputCache&&
		) noexcept = delete;

		CLIInputCache& operator = (
			CLIInputCache&&
		) = delete;

		CLIInputCache& operator = (
			const CLIInputCache&
		) = delete;

		bool setup();

		void setup(
			QLogicaeCore::Result<void>& result
		);

		bool clear();

		void clear(
			QLogicaeCore::Result<void>& result
		);

		Type& get(
			const std::string command_path,
			const std::string command_key
		);

		void get(
			QLogicaeCore::Result<Type&>& result,
			const std::string command_path,
			const std::string command_key
		);

		bool set(
			const std::string command_path,
			const std::string command_key,
			const Type& value
		);

		void set(
			QLogicaeCore::Result<void>& result,
			const std::string command_path,
			const std::string command_key,
			const Type& value
		);

	protected:
		std::unordered_map<std::string, Type> _inputs;
	};

	template <typename Type>
	CLIInputCache<Type>::CLIInputCache()
	{

	}

	template <typename Type>
	CLIInputCache<Type>::~CLIInputCache()
	{

	}

	template <typename Type>
	bool CLIInputCache<Type>::setup()
	{
		return true;
	}

	template <typename Type>
	void CLIInputCache<Type>::setup(
		QLogicaeCore::Result<void>& result
	)
	{
		result.set_to_good_status_without_value();
	}

	template <typename Type>
	bool CLIInputCache<Type>::clear()
	{
		return true;
	}

	template <typename Type>
	void CLIInputCache<Type>::clear(
		QLogicaeCore::Result<void>& result
	)
	{
		_inputs.clear();

		result.set_status_to_good();
	}

	template <typename Type>
	Type& CLIInputCache<Type>::get(
		const std::string command_path,
		const std::string command_key
	)
	{
		return _inputs
		[
			CLI_TRANSFORMER.to_input_command_path(
				command_path,
				command_key
			)
		];
	}

	template <typename Type>
	void CLIInputCache<Type>::get(
		QLogicaeCore::Result<Type&>& result,
		const std::string command_path,
		const std::string command_key
	)
	{
		QLogicaeCore::Result<std::string>
			input_command_path_result;

		CLI_TRANSFORMER.to_input_command_path(
			input_command_path_result,
			command_path,
			command_key
		);
		
		result.set_to_good_status_with_value(
			&input_command_path_result.get_value()
		);
	}

	template <typename Type>
	bool CLIInputCache<Type>::set(
		const std::string command_path,
		const std::string command_key,
		const Type& value
	)
	{
		_inputs
		[
			CLI_TRANSFORMER.to_input_command_path(
				command_path,
				command_key
			)
		] = value;

		return true;
	}

	template <typename Type>
	void CLIInputCache<Type>::set(
		QLogicaeCore::Result<void>& result,
		const std::string command_path,
		const std::string command_key,
		const Type& value
	)
	{
		QLogicaeCore::Result<std::string>
			input_command_path_result;

		CLI_TRANSFORMER.to_input_command_path(
			input_command_path_result,
			command_path,
			command_key
		);

		_inputs
		[
			CLI_TRANSFORMER.to_input_command_path(
				input_command_path_result,
				command_path,
				command_key
			)
		] = value;

		result.set_to_good_status_without_value();
	}

	static inline CLIInputCache<bool> CLI_BOOLEAN_INPUTS;

	static inline CLIInputCache<size_t> CLI_SIZE_T_INPUTS;

	static inline CLIInputCache<double> CLI_DOUBLE_INPUTS;

	static inline CLIInputCache<std::string> CLI_STRING_INPUTS;
}
