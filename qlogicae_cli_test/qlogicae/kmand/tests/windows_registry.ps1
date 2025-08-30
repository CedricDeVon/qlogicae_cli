
Describe "[qlogicae_cli windows-registry] test suite" {
    BeforeAll {
        $QLogicaeKmandInstance.BeforeAllTestsSetup()
        
        qlogicae_cli setup vs2022 application

        New-Item -Path "HKCU:\\$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistrySubPath)"
        Set-ItemProperty -Path "HKCU:\\$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistrySubPath)" -Name "$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistryKey)" -Value "$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistryValue)"
    }

    AfterAll {
        Remove-Item -Path "HKCU:\\$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistrySubPath)" -Recurse
        Remove-Item -Path "HKCU:\\Software\\Qlogicae\\Application\\$(($(Get-Content "$($QLogicaeKmandInstance.Configurations.RelativeQLogicaeConfigurationsPublicFilePath)" -Raw | ConvertFrom-Json).application.id))" -Recurse

        $QLogicaeKmandInstance.AfterAllTestsSetup()
    }

    Context ("[qlogicae_cli windows-registry] test cases") {
        It "[qlogicae_cli windows-registry]: should terminate" {
            $TestResult = qlogicae_cli windows-registry | Out-String        

            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli windows-registry --help]: should not be null or empty" {
            $TestResult = qlogicae_cli windows-registry --help | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }

    Context ("[qlogicae_cli windows-registry hkcu] test cases") {
        It "[qlogicae_cli windows-registry hkcu]: should terminate" {
            $TestResult = qlogicae_cli windows-registry hkcu | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli windows-registry hkcu --help]: should not be null or empty" {
            $TestResult = qlogicae_cli windows-registry hkcu --help | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }

    Context ("[qlogicae_cli windows-registry hkcu get] test cases") {
        It "[qlogicae_cli windows-registry hkcu get]: should terminate" {
            $TestResult = qlogicae_cli windows-registry hkcu get | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli windows-registry hkcu get --help]: should not be null or empty" {
            $TestResult = qlogicae_cli windows-registry hkcu get --help | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }

    Context ("[qlogicae_cli windows-registry hkcu get --sub-path] test cases") {
        It "[qlogicae_cli windows-registry hkcu get --sub-path='']: should terminate" {
            $TestResult = qlogicae_cli windows-registry hkcu get --sub-path='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli windows-registry hkcu get --sub-path='a']: should terminate" {
            $TestResult = qlogicae_cli windows-registry hkcu get --sub-path='a' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli windows-registry hkcu get --sub-path='$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistrySubPath)']: should return 'hkcu.name.development'" {
            $TestResult = qlogicae_cli windows-registry hkcu get --sub-path="$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistrySubPath)" | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty           
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistryValue)")) | Should -Be 1
        }
    }

    Context ("[qlogicae_cli windows-registry hkcu get --sub-path --is-verbose-logging-enabled] test cases") {
        It "[qlogicae_cli windows-registry hkcu get --sub-path='$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistrySubPath)' --is-verbose-logging-enabled='']: should terminate" {           
            $TestResult = qlogicae_cli windows-registry hkcu get --sub-path="$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistrySubPath)" --is-verbose-logging-enabled='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli windows-registry hkcu get --sub-path='$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistrySubPath)' --is-verbose-logging-enabled='fals']: should terminate" {        
            $TestResult = qlogicae_cli windows-registry hkcu get --sub-path="$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistrySubPath)" --is-verbose-logging-enabled='fals' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli windows-registry hkcu get --sub-path='$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistrySubPath)' --is-verbose-logging-enabled='tru']: should terminate" {        
            $TestResult = qlogicae_cli windows-registry hkcu get --sub-path="$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistrySubPath)" --is-verbose-logging-enabled='tru' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli windows-registry hkcu get --sub-path='$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistrySubPath)' --is-verbose-logging-enabled='false']: should return 'hkcu.name.development'" {        
            $TestResult = qlogicae_cli windows-registry hkcu get --sub-path="$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistrySubPath)" --is-verbose-logging-enabled='false' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistryValue)")) | Should -Be 1
        }

        It "[qlogicae_cli windows-registry hkcu get --sub-path='$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistrySubPath)' --is-verbose-logging-enabled='true']: should return 'hkcu.name.development'" {
            $TestResult = qlogicae_cli windows-registry hkcu get --sub-path="$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistrySubPath)" --is-verbose-logging-enabled='true' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistryValue)")) | Should -Be 1
        }
    }
    
    Context ("[qlogicae_cli windows-registry hkcu set] test cases") {
        It "[qlogicae_cli windows-registry hkcu set]: should terminate" {
            $TestResult = qlogicae_cli windows-registry hkcu set | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli windows-registry hkcu set --help]: should not be null or empty" {
            $TestResult = qlogicae_cli windows-registry hkcu set --help | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }

    Context ("[qlogicae_cli windows-registry hkcu set --sub-path --key --value] test cases") {
        It "[qlogicae_cli windows-registry hkcu set --sub-path='' --key='' --value='']: should terminate" {
            $TestResult = qlogicae_cli windows-registry hkcu set --sub-path='' --key='' --value='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli windows-registry hkcu set --sub-path='$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistrySubPath)' --key='$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistryKey)' --value='']: should terminate" {
            $TestResult = qlogicae_cli windows-registry hkcu set --sub-path="$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistrySubPath)" --key="$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistryKey)" --value="" | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }
        
        It "[qlogicae_cli windows-registry hkcu set --sub-path='$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistrySubPath)' --value='$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistryValue)' --key='']: should terminate" {
            $TestResult = qlogicae_cli windows-registry hkcu set --sub-path="$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistrySubPath)" --value="$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistryValue)" --key='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }
        
        It "[qlogicae_cli windows-registry hkcu set --key='$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistryKey)' --value='$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistryValue)' --sub-path='']: should terminate" {
            $TestResult = qlogicae_cli windows-registry hkcu set --key="$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistryKey)" --value="$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistryValue)" --sub-path="" | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli windows-registry hkcu set --sub-path='$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistrySubPath)' --key='$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistryKey)' --value='$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistryValue)']: should set sub-path key to 'hkcu.name.development'" {
            $TestResult = qlogicae_cli windows-registry hkcu set --sub-path="$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistrySubPath)" --key="$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistryKey)" --value="$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistryValue)" | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)
            
            $TestResult | Should -BeNullOrEmpty
        }
    }
   
    Context ("[qlogicae_cli windows-registry hkcu set --sub-path --key --value --is-verbose-logging-enabled] test cases") {
        It "[qlogicae_cli windows-registry hkcu set --sub-path='$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistrySubPath)' --key='$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistryKey)' --value='$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistryValue)' --is-verbose-logging-enabled='']: should terminate" {
            $TestResult = qlogicae_cli windows-registry hkcu set --sub-path="$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistrySubPath)" --key="$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistryKey)" --value="$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistryValue)" --is-verbose-logging-enabled='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli windows-registry hkcu set --sub-path='$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistrySubPath)' --key='$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistryKey)' --value='$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistryValue)' --is-verbose-logging-enabled='fals']: should terminate" {
            $TestResult = qlogicae_cli windows-registry hkcu set --sub-path="$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistrySubPath)" --key="$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistryKey)" --value="$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistryValue)" --is-verbose-logging-enabled='fals' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli windows-registry hkcu set --sub-path='$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistrySubPath)' --key='$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistryKey)' --value='$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistryValue)' --is-verbose-logging-enabled='tru']: should terminate" {
            $TestResult = qlogicae_cli windows-registry hkcu set --sub-path="$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistrySubPath)" --key="$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistryKey)" --value="$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistryValue)" --is-verbose-logging-enabled='tru' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli windows-registry hkcu set --sub-path='$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistrySubPath)' --key='$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistryKey)' --value='$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistryValue)' --is-verbose-logging-enabled='false']: should set sub-path key to 'hkcu.name.development'" {
            $TestResult = qlogicae_cli windows-registry hkcu set --sub-path="$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistrySubPath)" --key="$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistryKey)" --value="$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistryValue)" --is-verbose-logging-enabled='false' | Out-String
            
            $TestResult | Should -BeNullOrEmpty           
        }

        It "[qlogicae_cli windows-registry hkcu set --sub-path='$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistrySubPath)' --key='$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistryKey)' --value='$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistryValue)' --is-verbose-logging-enabled='true']: should set sub-path key to 'hkcu.name.development'" {
            $TestResult = qlogicae_cli windows-registry hkcu set --sub-path="$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistrySubPath)" --key="$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistryKey)" --value="$($QLogicaeKmandInstance.Configurations.MockHKCUEnvironmentRegistryValue)" --is-verbose-logging-enabled='true' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty           
        }
    }

    Context ("[qlogicae_cli windows-registry hkcu setup] test cases") {
        It "[qlogicae_cli windows-registry hkcu setup]: should terminate" {
            $TestResult = qlogicae_cli windows-registry hkcu setup | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli windows-registry hkcu setup --help]: should not be null or empty" {
            $TestResult = qlogicae_cli windows-registry hkcu setup --help | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }

    Context ("[qlogicae_cli windows-registry hkcu setup --environment-type] test cases") {
        It "[qlogicae_cli windows-registry hkcu setup --environment-type='']: should terminate" {
            $TestResult = qlogicae_cli windows-registry hkcu setup --environment-type='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli windows-registry hkcu setup --environment-type='a']: should terminate" {
            $TestResult = qlogicae_cli windows-registry hkcu setup --environment-type='a' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli windows-registry hkcu setup --environment-type='development']: should be null or empty" {
            $TestResult = qlogicae_cli windows-registry hkcu setup --environment-type='development' | Out-String

            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli windows-registry hkcu setup --environment-type='debug']: should be null or empty" {
            $TestResult = qlogicae_cli windows-registry hkcu setup --environment-type='debug' | Out-String

            $TestResult | Should -BeNullOrEmpty
        }
        
        It "[qlogicae_cli windows-registry hkcu setup --environment-type='test']: should be null or empty" {
            $TestResult = qlogicae_cli windows-registry hkcu setup --environment-type='test' | Out-String

            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli windows-registry hkcu setup --environment-type='release']: should be null or empty" {
            $TestResult = qlogicae_cli windows-registry hkcu setup --environment-type='release' | Out-String

            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli windows-registry hkcu setup --environment-type='all']: should be null or empty" {
            $TestResult = qlogicae_cli windows-registry hkcu setup --environment-type='all' | Out-String

            $TestResult | Should -BeNullOrEmpty
        }
    }
    
    Context ("[qlogicae_cli windows-registry hkcu setup --environment-type --is-verbose-logging-enabled] test cases") {   
        It "[qlogicae_cli windows-registry hkcu setup --environment-type='development' --is-verbose-logging-enabled='']: should terminate" {
            $TestResult = qlogicae_cli windows-registry hkcu setup --environment-type='development' --is-verbose-logging-enabled='' | Out-String

            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli windows-registry hkcu setup --environment-type='development' --is-verbose-logging-enabled='false']: should be null or empty" {
            $TestResult = qlogicae_cli windows-registry hkcu setup --environment-type='development' --is-verbose-logging-enabled='false' | Out-String

            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli windows-registry hkcu setup --environment-type='development' --is-verbose-logging-enabled='true']: should not be null or empty" {
            $TestResult = qlogicae_cli windows-registry hkcu setup --environment-type='development' --is-verbose-logging-enabled='true' | Out-String

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }
}
