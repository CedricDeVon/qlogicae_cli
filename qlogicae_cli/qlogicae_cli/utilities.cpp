#include "pch.hpp"

#include "utilities.hpp"

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
			QLogicaeCore::LOGGER.handle_exception(
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
				"QLogicaeCLI::Utilities::setup()",
				exception.what()
			);

			return QLogicaeCore::UTILITIES.STRING_NONE_1;
		}
	}

	std::string Utilities::get_application_about_details()
	{
		try
		{
			return get_application_full_name() + "\n\n" +
				"ID:\n" + QLogicaeCore::QLOGICAE_APPLICATION_UTILITIES.CONFIGURATIONS_APPLICATION_ID + "\n\n" +
				"Description:\n" + QLogicaeCore::QLOGICAE_APPLICATION_UTILITIES.CONFIGURATIONS_APPLICATION_DESCRIPTION + "\n\n" +
				"Architecture:\n" + QLogicaeCore::QLOGICAE_APPLICATION_UTILITIES.CONFIGURATIONS_APPLICATION_ARCHITECTURE + "\n\n" +
				"Authors:\n" + QLogicaeCore::QLOGICAE_APPLICATION_UTILITIES.CONFIGURATIONS_APPLICATION_AUTHORS + "\n\n" +
				"Repository:\n" + QLogicaeCore::QLOGICAE_APPLICATION_UTILITIES.CONFIGURATIONS_APPLICATION_URL + "\n";
		}
		catch (const std::exception& exception)
		{
			QLogicaeCore::LOGGER.handle_exception_async(
				"QLogicaeCLI::Utilities::setup()",
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
