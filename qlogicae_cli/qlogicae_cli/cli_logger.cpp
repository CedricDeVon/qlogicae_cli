#include "pch.hpp"

#include "cli_logger.hpp"

namespace QLogicaeCLI
{
	CLILogger::CLILogger()
	{

	}

	CLILogger::~CLILogger()
	{

	}

	bool CLILogger::setup()
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
				"QLogicaeCLI::CLILogger::setup()",
				exception.what()
			);

			return false;
		}
	}

	std::future<bool> CLILogger::setup_async()
	{
		std::promise<bool> promise;
		auto future = promise.get_future();

		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this,
			promise = std::move(promise)]() mutable
			{
				promise.set_value(
					setup()
				);
			}
		);

		return future;
	}

	void CLILogger::setup_async(
		QLogicaeCore::Result<std::future<void>>& result
	)
	{
		std::promise<void> promise;
		auto future = promise.get_future();

		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this,
			promise = std::move(promise)]() mutable
			{
				QLogicaeCore::Result<void> result;

				setup(
					result
				);

				promise.set_value();
			}
		);

		result.set_to_good_status_with_value(
			std::move(future)
		);
	}

	void CLILogger::setup(
		QLogicaeCore::Result<void>& result
	)
	{
		result.set_to_good_status_without_value();
	}

	void CLILogger::setup_async(
		const std::function<void(const bool& result)>& callback
	)
	{
		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, callback]() mutable
			{
				callback(
					setup()
				);
			}
		);
	}

	void CLILogger::setup_async(
		const std::function<void(QLogicaeCore::Result<void>& result)>& callback
	)
	{
		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, callback]() mutable
			{
				QLogicaeCore::Result<void> result;

				setup(result);

				callback(
					result
				);
			}
		);
	}

	void CLILogger::log_running(
		const std::string& command_name,
		QLogicaeCore::LogConfigurations& log_configurations
	)
	{
		try
		{
			QLogicaeCore::Result<void> result;

			log_running(
				result,
				command_name,
				log_configurations
			);
		}
		catch (const std::exception& exception)
		{
			QLogicaeCore::LOGGER.handle_exception(
				"QLogicaeCLI::CLILogger::log_running()",
				exception.what()
			);
		}
	}

	std::future<void> CLILogger::log_running_async(
		const std::string& command_name,
		QLogicaeCore::LogConfigurations& log_configurations
	)
	{
		std::promise<void> promise;
		auto future = promise.get_future();

		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, command_name, log_configurations,
			promise = std::move(promise)]() mutable
			{
				log_running(
					command_name,
					log_configurations
				);

				promise.set_value();
			}
		);

		return future;
	}

	void CLILogger::log_running_async(
		const std::function<void()>& callback,
		const std::string& command_name,
		QLogicaeCore::LogConfigurations& log_configurations
	)
	{
		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, command_name, log_configurations, callback]() mutable
			{
				log_running(
					command_name,
					log_configurations
				);

				callback();
			}
		);
	}

	void CLILogger::log_running(
		QLogicaeCore::Result<void>& result,
		const std::string& command_name,
		QLogicaeCore::LogConfigurations& log_configurations
	)
	{
		std::string text = "Command '" + command_name + "' running";

		QLogicaeCore::LOGGER.log_with_timestamp_to_console(
			result,
			text,
			log_configurations
		);
		QLogicaeCore::LOGGER.log_with_timestamp_to_files(
			result,
			text
		);
	}

	void CLILogger::log_running_async(
		QLogicaeCore::Result<std::future<void>>& result,
		const std::string& command_name,
		QLogicaeCore::LogConfigurations& log_configurations
	)
	{
		std::promise<void> promise;
		auto future = promise.get_future();

		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, command_name, log_configurations,
			promise = std::move(promise)]() mutable
			{
				QLogicaeCore::Result<void> result;

				log_running(
					result,
					command_name,
					log_configurations
				);

				promise.set_value();
			}
		);

		result.set_to_good_status_with_value(
			std::move(future)
		);
	}

	void CLILogger::log_running_async(
		const std::function<void(QLogicaeCore::Result<void>& result)>& callback,
		const std::string& command_name,
		QLogicaeCore::LogConfigurations& log_configurations
	)
	{
		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, command_name, log_configurations, callback]() mutable
			{
				QLogicaeCore::Result<void> result;

				log_running(
					result,
					command_name,
					log_configurations
				);

				callback(
					result
				);
			}
		);
	}

	void CLILogger::log(
		const std::string& text,
		QLogicaeCore::LogConfigurations& console_log_configurations,
		QLogicaeCore::LogConfigurations& file_log_configurations
	)
	{
		try
		{
			QLogicaeCore::Result<void> result;

			log(
				result,
				text,
				console_log_configurations,
				file_log_configurations
			);
		}
		catch (const std::exception& exception)
		{
			QLogicaeCore::LOGGER.handle_exception(
				"QLogicaeCLI::CLILogger::log()",
				exception.what()
			);
		}
	}

	std::future<void> CLILogger::log_async(
		const std::string& text,
		QLogicaeCore::LogConfigurations& console_log_configurations,
		QLogicaeCore::LogConfigurations& file_log_configurations
	)
	{
		std::promise<void> promise;
		auto future = promise.get_future();

		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, text, console_log_configurations, file_log_configurations,
			promise = std::move(promise)]() mutable
			{
				log(
					text,
					console_log_configurations,
					file_log_configurations
				);

				promise.set_value();
			}
		);

		return future;
	}

	void CLILogger::log_async(
		const std::function<void()>& callback,
		const std::string& text,
		QLogicaeCore::LogConfigurations& console_log_configurations,
		QLogicaeCore::LogConfigurations& file_log_configurations
	)
	{
		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, callback, text, console_log_configurations, file_log_configurations]() mutable
			{
				log(
					text,
					console_log_configurations,
					file_log_configurations
				);

				callback();
			}
		);
	}

	void CLILogger::log(
		QLogicaeCore::Result<void>& result,
		const std::string& text,
		QLogicaeCore::LogConfigurations& console_log_configurations,
		QLogicaeCore::LogConfigurations& file_log_configurations
	)
	{
		QLogicaeCore::LOGGER.log_with_timestamp_to_console(
			result,
			text,
			console_log_configurations
		);
		QLogicaeCore::LOGGER.log_with_timestamp_to_files(
			result,
			text,
			file_log_configurations
		);

		result.set_to_good_status_without_value();
	}

	void CLILogger::log_async(
		QLogicaeCore::Result<std::future<void>>& result,
		const std::string& text,
		QLogicaeCore::LogConfigurations& console_log_configurations,
		QLogicaeCore::LogConfigurations& file_log_configurations
	)
	{
		std::promise<void> promise;
		auto future = promise.get_future();

		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, text, console_log_configurations, file_log_configurations,
			promise = std::move(promise)]() mutable
			{
				QLogicaeCore::Result<void> result;

				log(
					result,
					text,
					console_log_configurations,
					file_log_configurations
				);

				promise.set_value();
			}
		);

		result.set_to_good_status_with_value(
			std::move(future)
		);
	}

	void CLILogger::log_async(
		const std::function<void(QLogicaeCore::Result<void>& result)>& callback,
		const std::string& text,
		QLogicaeCore::LogConfigurations& console_log_configurations,
		QLogicaeCore::LogConfigurations& file_log_configurations
	)
	{
		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, text, console_log_configurations, file_log_configurations, callback]() mutable
			{
				QLogicaeCore::Result<void> result;

				log(
					result,
					text,
					console_log_configurations,
					file_log_configurations
				);

				callback(
					result
				);
			}
		);
	}

	void CLILogger::log_complete(
		const std::string& command_name,
		QLogicaeCore::LogConfigurations& log_configurations
	)
	{
		try
		{
			QLogicaeCore::Result<void> result;

			log_complete(
				result,
				command_name,
				log_configurations
			);
		}
		catch (const std::exception& exception)
		{
			QLogicaeCore::LOGGER.handle_exception(
				"QLogicaeCLI::CLILogger::log_complete()",
				exception.what()
			);
		}
	}

	std::future<void> CLILogger::log_complete_async(
		const std::string& command_name,
		QLogicaeCore::LogConfigurations& log_configurations
	)
	{
		std::promise<void> promise;
		auto future = promise.get_future();

		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, command_name, log_configurations,
			promise = std::move(promise)]() mutable
			{
				log_complete(
					command_name,
					log_configurations
				);

				promise.set_value();
			}
		);

		return future;
	}

	void CLILogger::log_complete_async(
		const std::function<void()>& callback,
		const std::string& command_name,
		QLogicaeCore::LogConfigurations& log_configurations
	)
	{
		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, command_name, log_configurations, callback]() mutable
			{
				log_complete(
					command_name,
					log_configurations
				);

				callback();
			}
		);
	}

	void CLILogger::log_complete(
		QLogicaeCore::Result<void>& result,
		const std::string& command_name,
		QLogicaeCore::LogConfigurations& log_configurations
	)
	{
		std::string text = "Command '" + command_name + "' completed";

		QLogicaeCore::LOGGER.log_with_timestamp_to_console(
			result,
			text,
			log_configurations
		);
		QLogicaeCore::LOGGER.log_with_timestamp_to_files(
			result,
			text
		);
	}

	void CLILogger::log_complete_async(
		QLogicaeCore::Result<std::future<void>>& result,
		const std::string& command_name,
		QLogicaeCore::LogConfigurations& log_configurations
	)
	{
		std::promise<void> promise;
		auto future = promise.get_future();

		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, command_name, log_configurations,
			promise = std::move(promise)]() mutable
			{
				QLogicaeCore::Result<void> result;

				log_complete(
					result,
					command_name,
					log_configurations
				);

				promise.set_value();
			}
		);

		result.set_to_good_status_with_value(
			std::move(future)
		);
	}

	void CLILogger::log_complete_async(
		const std::function<void(QLogicaeCore::Result<void>& result)>& callback,
		const std::string& command_name,
		QLogicaeCore::LogConfigurations& log_configurations
	)
	{
		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, command_name, log_configurations, callback]() mutable
			{
				QLogicaeCore::Result<void> result;

				log_complete(
					result,
					command_name,
					log_configurations
				);

				callback(
					result
				);
			}
		);
	}

	CLILogger& CLILogger::get_instance()
	{
		static CLILogger instance;

		return instance;
	}

	void CLILogger::get_instance(
		QLogicaeCore::Result<CLILogger*>& result
	)
	{
		static CLILogger instance;

		result.set_to_good_status_with_value(&instance);
	}
}
