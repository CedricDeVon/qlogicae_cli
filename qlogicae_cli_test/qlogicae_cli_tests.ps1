
Describe "[qlogicae_cli] test suite" {
    BeforeAll {
        . $PSScriptRoot/qlogicae/configurations/imports.ps1
    }

    AfterAll {

    }

    It "[qlogicae_cli]: should be null or empty" {
        $TestResult = qlogicae_cli | Out-String        
        
        $TestResult | Should -BeNullOrEmpty
    }

    It "[qlogicae_cli --help]: should not be null or empty" {
        $TestResult = qlogicae_cli --help | Out-String        
        QLogicaePesterTest_Log -Text $TestResult

        $TestResult | Should -Not -BeNullOrEmpty
    }
}
