#pragma once

#include "transformer.hpp"

#include "qlogicae_core/includes/result.hpp"

namespace QLogicaeCLI
{
	template <typename Type>
	class InputCache
	{
	public:
		InputCache();

		~InputCache();

		InputCache(
			const InputCache& instance
		) = delete;

		InputCache(
			InputCache&& instance
		) noexcept = delete;

		InputCache& operator = (
			InputCache&& instance
		) = delete;

		InputCache& operator = (
			const InputCache& instance
		) = delete;

		bool setup();

		std::future<bool> setup_async();

		void setup_async(
			QLogicaeCore::Result<std::future<void>>& result
		);

		void setup(
			QLogicaeCore::Result<void>& result
		);

		std::future<bool> setup_async(
			const std::function<void(const bool& result)>& callback
		);

		void setup_async(
			const std::function<void(QLogicaeCore::Result<void>& result)>& callback
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
	InputCache<Type>::InputCache()
	{

	}

	template <typename Type>
	InputCache<Type>::~InputCache()
	{

	}

	template <typename Type>
	bool InputCache<Type>::setup()
	{
		try
		{
			QLogicaeCore::Result<void> result;

			setup(result);

			return result.is_status_safe();
		}
		catch (const std::exception& exception)
		{
			QLogicaeCore::LOGGER.handle_exception(
				"InputCache<Type>::setup()",
				exception.what()
			);

			return false;
		}
	}

	template <typename Type>
	void InputCache<Type>::setup(
		QLogicaeCore::Result<void>& result
	)
	{
		result.set_to_good_status_without_value();
	}


	template <typename Type>
	std::future<bool> InputCache<Type>::setup_async()
	{
		return std::async(
			std::launch::async, [this]() -> bool
			{
				return setup();
			}
		);
	}

	template <typename Type>
	void InputCache<Type>::setup_async(
		QLogicaeCore::Result<std::future<void>>& result
	)
	{
		result.set_to_good_status_with_value(
			std::async(
				std::launch::async, [this]() -> void
			{
				QLogicaeCore::Result<void> void_result;

				setup(void_result);

				void_result.set_to_good_status_without_value();
			}
		));
	}

	template <typename Type>
	bool InputCache<Type>::clear()
	{
		return true;
	}

	template <typename Type>
	void InputCache<Type>::clear(
		QLogicaeCore::Result<void>& result
	)
	{
		_inputs.clear();

		result.set_status_to_good();
	}

	template <typename Type>
	Type& InputCache<Type>::get(
		const std::string command_path,
		const std::string command_key
	)
	{
		return _inputs
		[
			TRANSFORMER.to_input_command_path(
				command_path,
				command_key
			)
		];
	}

	template <typename Type>
	void InputCache<Type>::get(
		QLogicaeCore::Result<Type&>& result,
		const std::string command_path,
		const std::string command_key
	)
	{
		QLogicaeCore::Result<std::string>
			input_command_path_result;

		TRANSFORMER.to_input_command_path(
			input_command_path_result,
			command_path,
			command_key
		);
		
		result.set_to_good_status_with_value(
			&input_command_path_result.get_value()
		);
	}

	template <typename Type>
	bool InputCache<Type>::set(
		const std::string command_path,
		const std::string command_key,
		const Type& value
	)
	{
		_inputs
		[
			TRANSFORMER.to_input_command_path(
				command_path,
				command_key
			)
		] = value;

		return true;
	}

	template <typename Type>
	void InputCache<Type>::set(
		QLogicaeCore::Result<void>& result,
		const std::string command_path,
		const std::string command_key,
		const Type& value
	)
	{
		QLogicaeCore::Result<std::string>
			input_command_path_result;

		TRANSFORMER.to_input_command_path(
			input_command_path_result,
			command_path,
			command_key
		);

		_inputs
		[
			TRANSFORMER.to_input_command_path(
				input_command_path_result,
				command_path,
				command_key
			)
		] = value;

		result.set_to_good_status_without_value();
	}

	static inline InputCache<bool> BOOLEAN_INPUTS;

	static inline InputCache<size_t> SIZE_T_INPUTS;

	static inline InputCache<double> DOUBLE_INPUTS;

	static inline InputCache<std::string> STRING_INPUTS;
}
