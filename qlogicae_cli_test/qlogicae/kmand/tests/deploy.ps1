
Describe "[qlogicae_cli deploy] test suite" {
    BeforeAll {
        $QLogicaeKmandInstance.BeforeAllTestsSetup()

        qlogicae_cli setup vs2022 application
        
        $ClientQLogicaePrivateFile = Get-Content "$($QLogicaeKmandInstance.Configurations.RelativeQLogicaePrivateFilePath)" -Raw | ConvertFrom-Json
        $ClientQLogicaePrivateFile.inno_setup.input_folder_path = "$($QLogicaeKmandInstance.Configurations.MockDeployInnoSetupInputFolderPath)"
        $ClientQLogicaePrivateFile.inno_setup.output_folder_path = "$($QLogicaeKmandInstance.Configurations.MockDeployInnoSetupOutputFolderPath)"
        $ClientQLogicaePrivateFile.application.executable_name = "$($QLogicaeKmandInstance.Configurations.RelativeQLogicaePrivateFilePath)"
        $ClientQLogicaePrivateFile | ConvertTo-Json -Depth 20 | Set-Content "$($QLogicaeKmandInstance.Configurations.MockDeployExecutableName)"

        xcopy "$($QLogicaeKmandInstance.Configurations.DotQLogicaeKmandBuildsCLIFolderPath)" "$($QLogicaeKmandInstance.Configurations.DotQLogicaeKmandEnvironmentFolderPath)" /E /Y /I        
    }

    AfterAll {
        $QLogicaeKmandInstance.AfterAllTestsSetup()
    }

    Context ("[qlogicae_cli deploy] test cases") {
        It "[qlogicae_cli deploy]: should terminate" {
            $TestResult = qlogicae_cli deploy | Out-String        

            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli deploy --help]: should not be null or empty" {
            $TestResult = qlogicae_cli deploy --help | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }

    Context ("[qlogicae_cli deploy inno-setup] test cases") {
        It "[qlogicae_cli deploy inno-setup --help]: should not be null or empty" {
            $TestResult = qlogicae_cli deploy inno-setup --help | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }

        It "[qlogicae_cli deploy inno-setup]: should not be null or empty" {
            $TestResult = qlogicae_cli deploy inno-setup | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }

    Context ("[qlogicae_cli deploy inno-setup --is-verbose-logging-enabled] test cases") {
        It "[qlogicae_cli deploy inno-setup --is-verbose-logging-enabled='']: should terminate" {
            $TestResult = qlogicae_cli deploy inno-setup --is-verbose-logging-enabled='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli deploy inno-setup --is-verbose-logging-enabled='fals']: should terminate" {
            $TestResult = qlogicae_cli deploy inno-setup --is-verbose-logging-enabled='fals' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli deploy inno-setup --is-verbose-logging-enabled='tru']: should terminate" {
            $TestResult = qlogicae_cli deploy inno-setup --is-verbose-logging-enabled='tru' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli deploy inno-setup --is-verbose-logging-enabled='false']: should not be null or empty" {
            $TestResult = qlogicae_cli deploy inno-setup --is-verbose-logging-enabled='false' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }

        It "[qlogicae_cli deploy inno-setup --is-verbose-logging-enabled='true']: should not be null or empty" {
            $TestResult = qlogicae_cli deploy inno-setup --is-verbose-logging-enabled='true' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }
}
