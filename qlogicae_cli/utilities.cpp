#include "pch.hpp"

#include "utilities.hpp"

namespace QLogicaeCLI
{
	Utilities::Utilities()
	{
		
	}

	void Utilities::setup()
	{
		try
		{
			QLogicaeCore::QLOGICAE_APPLICATION.setup();
		}
		catch (const std::exception& exception)
		{
			QLogicaeCore::QLOGICAE_APPLICATION_LOGGER.MAIN_LOGGER.force_log_to_console_and_file_async(
				"Utilities::setup()",
				exception
			);
		}
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
			QLogicaeCore::QLOGICAE_APPLICATION_LOGGER.MAIN_LOGGER.force_log_to_console_and_file_async(
				"Utilities::get_application_full_name()",
				exception
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
			QLogicaeCore::QLOGICAE_APPLICATION_LOGGER.MAIN_LOGGER.force_log_to_console_and_file_async(
				"Utilities::get_application_about_details()",
				exception
			);

			return QLogicaeCore::UTILITIES.STRING_NONE_1;
		}
	}

	Utilities& Utilities::get_instance()
	{
		static Utilities instance;

		return instance;
	}
}
