#include "pch.hpp"

#include "../includes/logger.hpp"

namespace QLogicaeCLI
{
	Logger::Logger()
	{

	}

	Logger::~Logger()
	{

	}

	bool Logger::setup()
	{
		try
		{
			QLogicaeCore::Result<void> result;

			setup(result);

			return result.is_status_safe();
		}
		catch (const std::exception& exception)
		{
			QLogicaeCore::LOGGER.handle_exception_async(
				"QLogicaeCLI::Logger::setup()",
				exception.what()
			);

			return false;
		}
	}

	std::future<bool> Logger::setup_async()
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

	void Logger::setup_async(
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

	void Logger::setup(
		QLogicaeCore::Result<void>& result
	)
	{
		result.set_to_good_status_without_value();
	}

	void Logger::setup_async(
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

	void Logger::setup_async(
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

	bool Logger::terminate()
	{
		try
		{
			QLogicaeCore::Result<void> result;

			terminate(result);

			return result.is_status_safe();
		}
		catch (const std::exception& exception)
		{
			QLogicaeCore::LOGGER.handle_exception_async(
				"QLogicaeCLI::Logger::terminate()",
				exception.what()
			);

			return false;
		}
	}

	std::future<bool> Logger::terminate_async()
	{
		std::promise<bool> promise;
		auto future = promise.get_future();

		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this,
			promise = std::move(promise)]() mutable
			{
				promise.set_value(
					terminate()
				);
			}
		);

		return future;
	}

	void Logger::terminate_async(
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

				terminate(
					result
				);

				promise.set_value();
			}
		);

		result.set_to_good_status_with_value(
			std::move(future)
		);
	}

	void Logger::terminate(
		QLogicaeCore::Result<void>& result
	)
	{
		result.set_to_good_status_without_value();
	}

	std::future<bool> Logger::terminate_async(
		const std::function<void(const bool& result)>& callback
	)
	{
		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, callback]() mutable
			{
				callback(
					terminate()
				);
			}
		);
	}

	void Logger::terminate_async(
		const std::function<void(QLogicaeCore::Result<void>& result)>& callback
	)
	{
		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, callback]() mutable
			{
				QLogicaeCore::Result<void> result;

				terminate(result);

				callback(
					result
				);
			}
		);
	}

	void Logger::log_running(
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
			QLogicaeCore::LOGGER.handle_exception_async(
				"QLogicaeCLI::Logger::log_running()",
				exception.what()
			);
		}
	}

	std::future<void> Logger::log_running_async(
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

	void Logger::log_running_async(
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

	void Logger::log_running(
		QLogicaeCore::Result<void>& result,
		const std::string& command_name,
		QLogicaeCore::LogConfigurations& log_configurations
	)
	{
		std::string text = "Command '" + command_name + "' running";

		QLogicaeCore::LOGGER.log_with_timestamp(
			result,
			text,
			log_configurations
		);
	}

	void Logger::log_running_async(
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

	void Logger::log_running_async(
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

	void Logger::log(
		const std::string& text,
		QLogicaeCore::LogConfigurations& log_configurations
	)
	{
		try
		{
			QLogicaeCore::Result<void> result;

			log(
				result,
				text,
				log_configurations
			);
		}
		catch (const std::exception& exception)
		{
			QLogicaeCore::LOGGER.handle_exception_async(
				"QLogicaeCLI::Logger::log()",
				exception.what()
			);
		}
	}

	std::future<void> Logger::log_async(
		const std::string& text,
		QLogicaeCore::LogConfigurations& log_configurations
	)
	{
		std::promise<void> promise;
		auto future = promise.get_future();

		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, text, log_configurations,
			promise = std::move(promise)]() mutable
			{
				log(
					text,
					log_configurations
				);

				promise.set_value();
			}
		);

		return future;
	}

	void Logger::log_async(
		const std::function<void()>& callback,
		const std::string& text,
		QLogicaeCore::LogConfigurations& log_configurations
	)
	{
		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, callback, text, log_configurations]() mutable
			{
				log(
					text,
					log_configurations
				);

				callback();
			}
		);
	}

	void Logger::log(
		QLogicaeCore::Result<void>& result,
		const std::string& text,
		QLogicaeCore::LogConfigurations& log_configurations
	)
	{
		QLogicaeCore::LOGGER.log_with_timestamp(
			result,
			text,
			log_configurations
		);

		result.set_to_good_status_without_value();
	}

	void Logger::log_async(
		QLogicaeCore::Result<std::future<void>>& result,
		const std::string& text,
		QLogicaeCore::LogConfigurations& log_configurations
	)
	{
		std::promise<void> promise;
		auto future = promise.get_future();

		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, text, log_configurations,
			promise = std::move(promise)]() mutable
			{
				QLogicaeCore::Result<void> result;

				log(
					result,
					text,
					log_configurations
				);

				promise.set_value();
			}
		);

		result.set_to_good_status_with_value(
			std::move(future)
		);
	}

	void Logger::log_async(
		const std::function<void(QLogicaeCore::Result<void>& result)>& callback,
		const std::string& text,
		QLogicaeCore::LogConfigurations& log_configurations
	)
	{
		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, text, log_configurations, callback]() mutable
			{
				QLogicaeCore::Result<void> result;

				log(
					result,
					text,
					log_configurations
				);

				callback(
					result
				);
			}
		);
	}

	void Logger::log_complete(
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
			QLogicaeCore::LOGGER.handle_exception_async(
				"QLogicaeCLI::Logger::log_complete()",
				exception.what()
			);
		}
	}

	std::future<void> Logger::log_complete_async(
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

	void Logger::log_complete_async(
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

	void Logger::log_complete(
		QLogicaeCore::Result<void>& result,
		const std::string& command_name,
		QLogicaeCore::LogConfigurations& log_configurations
	)
	{
		std::string text = "Command '" + command_name + "' completed";

		QLogicaeCore::LOGGER.log_with_timestamp(
			result,
			text,
			log_configurations
		);
	}

	void Logger::log_complete_async(
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

	void Logger::log_complete_async(
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

	Logger& Logger::get_instance()
	{
		QLogicaeCore::Result<Logger*> result;

		get_instance(
			result
		);

		return *result.get_value();
	}

	void Logger::get_instance(
		QLogicaeCore::Result<Logger*>& result
	)
	{
		static Logger instance;

		result.set_to_good_status_with_value(
			&instance
		);
	}
}
