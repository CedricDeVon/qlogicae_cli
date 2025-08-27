
Describe "[qlogicae_cli] test suite" {
    BeforeAll {       
        . $PSScriptRoot/imports.ps1

        QLogicaePesterTest_BeforeAllTestsSetup
    }

    AfterAll {
        QLogicaePesterTest_AfterAllTestsSetup
    }

    Context "[qlogicae_cli] test cases" {
        It "[qlogicae_cli]: should be null or empty" {
            $TestResult = qlogicae_cli | Out-String        
        
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli --help]: should not be null or empty" {
            $TestResult = qlogicae_cli --help | Out-String        
            QLogicaePesterTest_ConsoleLog -Text $TestResult

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }
}
