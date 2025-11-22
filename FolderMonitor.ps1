# Folder to monitor
$folder = "$env:USERPROFILE\afolder"
$targetFile = "$folder\miarchivo.txt"

function Test-FileLocked {
    param ($path)

    try {
        $fs = [System.IO.File]::Open($path,
            [System.IO.FileMode]::Open,
            [System.IO.FileAccess]::ReadWrite,
            [System.IO.FileShare]::None
        )
        $fs.Close()
        return $false  # Not locked
    }
    catch {
        return $true   # Locked
    }
}

while ($true) {

    # Fast existence check
    if (-not (Test-Path -LiteralPath $targetFile)) {
        Write-Host "ERROR: File not found. Shutting down immediately."
        Start-Process "shutdown.exe" "/s /f /t 0"
        break
    }

    # Check if locked by another process
    if (Test-FileLocked $targetFile) {
        # Locked → do nothing
    }
    else {
        # Not locked → open in background
        Start-Process $targetFile -WindowStyle Hidden
    }

    Start-Sleep -Milliseconds 500
}
