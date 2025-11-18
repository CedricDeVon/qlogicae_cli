#include "pch.hpp"

#include "../includes/utilities.hpp"

namespace QLogicaeCLI
{
	Utilities::Utilities()
	{
		
	}

	Utilities::~Utilities()
	{

	}

	bool Utilities::setup()
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
				"QLogicaeCLI::Utilities::setup()",
				exception.what()
			);

			return false;
		}
	}

	std::future<bool> Utilities::setup_async()
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

	void Utilities::setup_async(
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

	void Utilities::setup(
		QLogicaeCore::Result<void>& result
	)
	{		
		RELATIVE_CLI_FOLDER_PATH = "cli";

		RELATIVE_QLOGICAE_DOT_QLOGICAE_CLI_FOLDER_PATH =
			QLogicaeCore::UTILITIES.RELATIVE_QLOGICAE_FOLDER_PATH_1 +
			"\\" + QLogicaeCore::UTILITIES.RELATIVE_DOT_QLOGICAE_FOLDER_PATH_1 +
			"\\" + RELATIVE_CLI_FOLDER_PATH;

		RELATIVE_QLOGICAE_CLI_SETUP_VS2022_APPLICATION_FOLDER_PATH =
			QLogicaeCore::UTILITIES.RELATIVE_QLOGICAE_FOLDER_PATH_1 +
			"\\" + RELATIVE_CLI_FOLDER_PATH + 
			"\\" + QLogicaeCore::UTILITIES.RELATIVE_SETUP_FOLDER_PATH + 
			"\\" + QLogicaeCore::UTILITIES.VISUAL_STUDIO_2022_1 + 
			"\\" + QLogicaeCore::UTILITIES.RELATIVE_APPLICATION_FOLDER_PATH;

		RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_CONFIGURATIONS_QLOGICAE_FILE_PATH =
			QLogicaeCore::UTILITIES.RELATIVE_QLOGICAE_FOLDER_PATH_1 +
			"\\" + QLogicaeCore::UTILITIES.RELATIVE_DOT_QLOGICAE_FOLDER_PATH_1 +
			"\\" + QLogicaeCore::UTILITIES.RELATIVE_APPLICATION_FOLDER_PATH +
			"\\" + QLogicaeCore::UTILITIES.RELATIVE_CONFIGURATIONS_FOLDER_PATH +
			"\\" + QLogicaeCore::UTILITIES.RELATIVE_QLOGICAE_FILE_PATH;

		RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_TEMPLATES_FOLDER_PATH =
			QLogicaeCore::UTILITIES.RELATIVE_QLOGICAE_FOLDER_PATH_1 +
			"\\" + QLogicaeCore::UTILITIES.RELATIVE_DOT_QLOGICAE_FOLDER_PATH_1 +
			"\\" + QLogicaeCore::UTILITIES.RELATIVE_APPLICATION_FOLDER_PATH +
			"\\" + QLogicaeCore::UTILITIES.RELATIVE_TEMPLATES_FOLDER_PATH;

		RELATIVE_BUILD_QLOGICAE_APPLICATION_CONFIGURATIONS_QLOGICAE_FILE_PATH =
			QLogicaeCore::UTILITIES.RELATIVE_BUILD_FOLDER_PATH +
			"\\" + QLogicaeCore::UTILITIES.RELATIVE_QLOGICAE_FOLDER_PATH_1 +
			"\\" + QLogicaeCore::UTILITIES.RELATIVE_APPLICATION_FOLDER_PATH +
			"\\" + QLogicaeCore::UTILITIES.RELATIVE_CONFIGURATIONS_FOLDER_PATH +
			"\\" + QLogicaeCore::UTILITIES.RELATIVE_QLOGICAE_FILE_PATH;

		RELATIVE_BUILD_QLOGICAE_APPLICATION_CONFIGURATIONS_ENVIRONMENT_FILE_PATH =
			QLogicaeCore::UTILITIES.RELATIVE_BUILD_FOLDER_PATH +
			"\\" + QLogicaeCore::UTILITIES.RELATIVE_QLOGICAE_FOLDER_PATH_1 +
			"\\" + QLogicaeCore::UTILITIES.RELATIVE_APPLICATION_FOLDER_PATH +
			"\\" + QLogicaeCore::UTILITIES.RELATIVE_CONFIGURATIONS_FOLDER_PATH +
			"\\" + QLogicaeCore::UTILITIES.RELATIVE_ENVIRONMENT_FILE_PATH;

		APPLICATION_QLOGICAE_FILE.setup(
			QLogicaeCore::UTILITIES.FULL_APPLICATION_QLOGICAE_PUBLIC_APPLICATION_CONFIGURATIONS_QLOGICAE_FILE_PATH
		);

		result.set_to_good_status_without_value();
	}

	std::future<bool> Utilities::setup_async(
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

	void Utilities::setup_async(
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

	bool Utilities::terminate()
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
				"QLogicaeCLI::Utilities::terminate()",
				exception.what()
			);

			return false;
		}
	}

	std::future<bool> Utilities::terminate_async()
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

	void Utilities::terminate_async(
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

	void Utilities::terminate(
		QLogicaeCore::Result<void>& result
	)
	{
		result.set_to_good_status_without_value();
	}

	std::future<bool> Utilities::terminate_async(
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

	void Utilities::terminate_async(
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

	std::string Utilities::get_application_full_name()
	{
		try
		{
			return QLogicaeCore::QLOGICAE_APPLICATION_UTILITIES.CONFIGURATIONS_APPLICATION_NAME + " " +
				"(" + QLogicaeCore::QLOGICAE_APPLICATION_UTILITIES.CONFIGURATIONS_APPLICATION_VERSION + ")";
		}
		catch (const std::exception& exception)
		{
			QLogicaeCore::LOGGER.handle_exception_async(
				"QLogicaeCLI::Utilities::get_application_full_name()",
				exception.what()
			);

			return QLogicaeCore::UTILITIES.STRING_NONE_1;
		}
	}

	std::string Utilities::get_application_about_details()
	{
		try
		{
			return
				"\nName: \t\t\t" + QLogicaeCore::QLOGICAE_APPLICATION_UTILITIES.CONFIGURATIONS_APPLICATION_NAME + "\n" +
				"Version: \t\t" + QLogicaeCore::QLOGICAE_APPLICATION_UTILITIES.CONFIGURATIONS_APPLICATION_VERSION + "\n" +
				"Description: \t\t" + QLogicaeCore::QLOGICAE_APPLICATION_UTILITIES.CONFIGURATIONS_APPLICATION_DESCRIPTION + "\n" +
				"Author(s): \t\t" + QLogicaeCore::QLOGICAE_APPLICATION_UTILITIES.CONFIGURATIONS_APPLICATION_AUTHORS + "\n" +
				"Repository: \t\t" + QLogicaeCore::QLOGICAE_APPLICATION_UTILITIES.CONFIGURATIONS_APPLICATION_URL + "\n" +
				"Architecture: \t\t" + QLogicaeCore::QLOGICAE_APPLICATION_UTILITIES.CONFIGURATIONS_APPLICATION_ARCHITECTURE + "\n\n";
		}
		catch (const std::exception& exception)
		{
			QLogicaeCore::LOGGER.handle_exception_async(
				"QLogicaeCLI::Utilities::get_application_about_details()",
				exception.what()
			);

			return QLogicaeCore::UTILITIES.STRING_NONE_1;
		}
	}

	Utilities& Utilities::get_instance()
	{
		static Utilities instance;

		return instance;
	}

	void Utilities::get_instance(
		QLogicaeCore::Result<Utilities*>& result
	)
	{
		static Utilities instance;

		result.set_to_good_status_with_value(
			&instance
		);
	}
}
