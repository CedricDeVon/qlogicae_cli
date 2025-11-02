#pragma once

#include "qlogicae_core/includes/result.hpp"
#include "qlogicae_core/includes/logger.hpp"
#include "qlogicae_core/includes/transformer.hpp"

namespace QLogicaeCLI
{
	class Transformer
	{
	public:
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

		bool terminate();

		std::future<bool> terminate_async();

		void terminate_async(
			QLogicaeCore::Result<std::future<void>>& result
		);

		void terminate(
			QLogicaeCore::Result<void>& result
		);

		std::future<bool> terminate_async(
			const std::function<void(const bool& result)>& callback
		);

		void terminate_async(
			const std::function<void(QLogicaeCore::Result<void>& result)>& callback
		);

		std::string to_input_command_path(
			const std::string command_path,
			const std::string command_key
		);

		void to_input_command_path(
			QLogicaeCore::Result<std::string>& result,
			const std::string command_path,
			const std::string command_key
		);

		std::string to_log_running_timestamp(
			const bool& is_enabled = true
		);

		std::string to_log_complete_timestamp(
			const bool& is_enabled = true
		);

		std::string to_log_info_timestamp(
			const std::string& text = "",
			const bool& is_enabled = true
		);

		std::string to_log_success_timestamp(
			const std::string& text = "",
			const bool& is_enabled = true
		);

		std::string to_log_warning_timestamp(
			const std::string& text = "",
			const bool& is_enabled = true
		);

		std::string to_log_exception_timestamp(
			const std::string& text = "",
			const bool& is_enabled = true
		);

		static Transformer& get_instance();

		static void get_instance(
			QLogicaeCore::Result<Transformer*>& result
		);

	protected:
		Transformer();

		~Transformer();

		Transformer(
			const Transformer& instance
		) = delete;

		Transformer(
			Transformer&& instance
		) noexcept = delete;

		Transformer& operator = (
			Transformer&& instance
		) = delete;

		Transformer& operator = (
			const Transformer& instance
		) = delete;
	};

	static inline Transformer& TRANSFORMER =
		Transformer::get_instance();
}
