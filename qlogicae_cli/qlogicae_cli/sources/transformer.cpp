#include "pch.hpp"

#include "../includes/transformer.hpp"

namespace QLogicaeCLI
{
	Transformer::Transformer()
	{

	}

	Transformer::~Transformer()
	{

	}

	bool Transformer::setup()
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
				"QLogicaeCLI::Transformer::setup()",
				exception.what()
			);

			return false;
		}
	}

	std::future<bool> Transformer::setup_async()
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

	void Transformer::setup_async(
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

	void Transformer::setup(
		QLogicaeCore::Result<void>& result
	)
	{
		result.set_to_good_status_without_value();
	}

	std::future<bool> Transformer::setup_async(
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

	void Transformer::setup_async(
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

	bool Transformer::terminate()
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
				"QLogicaeCLI::Transformer::terminate()",
				exception.what()
			);

			return false;
		}
	}

	std::future<bool> Transformer::terminate_async()
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

	void Transformer::terminate_async(
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

	void Transformer::terminate(
		QLogicaeCore::Result<void>& result
	)
	{
		result.set_to_good_status_without_value();
	}

	std::future<bool> Transformer::terminate_async(
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

	void Transformer::terminate_async(
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

	std::string Transformer::to_log_running_timestamp(
		const bool& is_enabled
	)
	{
		if (is_enabled)
		{
			return QLogicaeCore::TRANSFORMER.to_log_format(
				"Running...",
				QLogicaeCore::LogLevel::HIGHLIGHTED_INFO
			);
		}

		return "";
	}

	std::string Transformer::to_log_complete_timestamp(
		const bool& is_enabled
	)
	{
		if (is_enabled)
		{
			return QLogicaeCore::TRANSFORMER.to_log_format(
				"Complete!",
				QLogicaeCore::LogLevel::HIGHLIGHTED_INFO
			);
		}

		return "";
	}

	std::string Transformer::to_log_info_timestamp(
		const std::string& text,
		const bool& is_enabled
	)
	{
		if (is_enabled)
		{
			return QLogicaeCore::TRANSFORMER.to_log_format(
				text,
				QLogicaeCore::LogLevel::INFO
			);
		}

		return "";
	}

	std::string Transformer::to_log_success_timestamp(
		const std::string& text,
		const bool& is_enabled
	)
	{
		if (is_enabled)
		{
			return QLogicaeCore::TRANSFORMER.to_log_format(
				text,
				QLogicaeCore::LogLevel::SUCCESS
			);
		}

		return "";
	}

	std::string Transformer::to_log_warning_timestamp(
		const std::string& text,
		const bool& is_enabled
	)
	{
		if (is_enabled)
		{
			return QLogicaeCore::TRANSFORMER.to_log_format(
				text,
				QLogicaeCore::LogLevel::WARNING
			);
		}

		return "";
	}

	std::string Transformer::to_log_exception_timestamp(
		const std::string& text, const bool& is_enabled
	)
	{
		if (is_enabled)
		{
			return QLogicaeCore::TRANSFORMER.to_log_format(
				text,
				QLogicaeCore::LogLevel::EXCEPTION
			);
		}

		return "";
	}

	std::string Transformer::to_input_command_path(
		const std::string command_path,
		const std::string command_key
	)
	{
		return command_path +
			"___" + command_key;
	}

	void Transformer::to_input_command_path(
		QLogicaeCore::Result<std::string>& result,
		const std::string command_path,
		const std::string command_key
	)
	{
		result.set_to_good_status_with_value(
			command_path +
			"___" + command_key
		);
	}

	Transformer& Transformer::get_instance()
	{
		QLogicaeCore::Result<Transformer*> result;

		get_instance(
			result
		);

		return *result.get_value();
	}

	void Transformer::get_instance(
		QLogicaeCore::Result<Transformer*>& result
	)
	{
		static Transformer instance;

		result.set_to_good_status_with_value(
			&instance
		);
	}
}
