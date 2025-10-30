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
		const bool& is_enabled
	)
	{
		try
		{
			QLogicaeCore::Result<void> result;

			log_running(
				result,
				is_enabled
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
		const bool& is_enabled
	)
	{
		std::promise<void> promise;
		auto future = promise.get_future();

		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, is_enabled,
			promise = std::move(promise)]() mutable
			{
				log_running(
					is_enabled
				);

				promise.set_value();
			}
		);

		return future;
	}

	void CLILogger::log_running_async(
		const std::function<void()>& callback,
		const bool& is_enabled
	)
	{
		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, is_enabled, callback]() mutable
			{
				log_running(
					is_enabled
				);

				callback();
			}
		);
	}

	void CLILogger::log_running(
		QLogicaeCore::Result<void>& result,
		const bool& is_enabled
	)
	{
		QLogicaeCore::LOGGER.log_timestamp(
			result,
			"Running...",
			QLogicaeCore::LogLevel::HIGHLIGHTED_INFO,
			is_enabled
		);
	}

	void CLILogger::log_running_async(
		QLogicaeCore::Result<std::future<void>>& result,
		const bool& is_enabled
	)
	{
		std::promise<void> promise;
		auto future = promise.get_future();

		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, is_enabled,
			promise = std::move(promise)]() mutable
			{
				QLogicaeCore::Result<void> result;

				log_running(
					result,
					is_enabled
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
		const bool& is_enabled
	)
	{
		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, is_enabled, callback]() mutable
			{
				QLogicaeCore::Result<void> result;

				log_running(
					result,
					is_enabled
				);

				callback(
					result
				);
			}
		);
	}

	void CLILogger::log(
		const bool& is_enabled,
		const std::string& text
	)
	{
		try
		{
			QLogicaeCore::Result<void> result;

			log(
				result,
				is_enabled,
				text
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
		const bool& is_enabled,
		const std::string& text
	)
	{
		std::promise<void> promise;
		auto future = promise.get_future();

		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, text, is_enabled,
			promise = std::move(promise)]() mutable
			{
				log(
					is_enabled,
					text
				);

				promise.set_value();
			}
		);

		return future;
	}

	void CLILogger::log_async(
		const std::function<void()>& callback,
		const bool& is_enabled,
		const std::string& text
	)
	{
		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, text, is_enabled, callback]() mutable
			{
				log(
					is_enabled,
					text
				);

				callback();
			}
		);
	}

	void CLILogger::log(
		QLogicaeCore::Result<void>& result,
		const bool& is_enabled,
		const std::string& text
	)
	{
		QLogicaeCore::LOGGER.log_timestamp(
			result,
			text,
			QLogicaeCore::LogLevel::INFO,
			is_enabled,
			true
		);
	}

	void CLILogger::log_async(
		QLogicaeCore::Result<std::future<void>>& result,
		const bool& is_enabled,
		const std::string& text
	)
	{
		std::promise<void> promise;
		auto future = promise.get_future();

		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, text, is_enabled,
			promise = std::move(promise)]() mutable
			{
				QLogicaeCore::Result<void> result;

				log(
					result,
					is_enabled,
					text
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
		const bool& is_enabled,
		const std::string& text
	)
	{
		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, text, is_enabled, callback]() mutable
			{
				QLogicaeCore::Result<void> result;

				log(
					result,
					is_enabled,
					text
				);

				callback(
					result
				);
			}
		);
	}

	void CLILogger::log_complete(
		const bool& is_enabled
	)
	{
		try
		{
			QLogicaeCore::Result<void> result;

			log_complete(
				result,
				is_enabled
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
		const bool& is_enabled
	)
	{
		std::promise<void> promise;
		auto future = promise.get_future();

		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, is_enabled,
			promise = std::move(promise)]() mutable
			{
				log_complete(
					is_enabled
				);

				promise.set_value();
			}
		);

		return future;
	}

	void CLILogger::log_complete_async(
		const std::function<void()>& callback,
		const bool& is_enabled
	)
	{
		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, is_enabled, callback]() mutable
			{
				log_complete(
					is_enabled
				);

				callback();
			}
		);
	}

	void CLILogger::log_complete(
		QLogicaeCore::Result<void>& result,
		const bool& is_enabled
	)
	{
		QLogicaeCore::LOGGER.log_timestamp(
			result,
			"Complete!",
			QLogicaeCore::LogLevel::HIGHLIGHTED_INFO,
			is_enabled
		);
	}

	void CLILogger::log_complete_async(
		QLogicaeCore::Result<std::future<void>>& result,
		const bool& is_enabled
	)
	{
		std::promise<void> promise;
		auto future = promise.get_future();

		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, is_enabled,
			promise = std::move(promise)]() mutable
			{
				QLogicaeCore::Result<void> result;

				log_complete(
					result,
					is_enabled
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
		const bool& is_enabled
	)
	{
		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, is_enabled, callback]() mutable
			{
				QLogicaeCore::Result<void> result;

				log_complete(
					result,
					is_enabled
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
